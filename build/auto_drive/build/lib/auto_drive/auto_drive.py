import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
import math
import numpy as np

class AutonomousVehicle(Node):
    def __init__(self):
        super().__init__('auto_drive')

        # Publisher for controlling the vehicle
        self.cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        
        # Subscribers for GPS (Odometry) and LiDAR (LaserScan) data
        self.create_subscription(Odometry, '/gps', self.gps_callback, 10)
        self.create_subscription(LaserScan, '/front_lidar', self.lidar_callback, 10)
        
        # Variables to hold sensor data
        self.current_position = (0, 0)
        self.current_orientation = 0  # yaw angle (radians)
        self.goal_position = (5, 5)  # Example goal position
        self.lidar_data = []
        
        # PID parameters for control (simplified)
        self.kp = 0.5
        self.ki = 0.1
        self.kd = 0.1
        self.prev_error = 0
        self.integral = 0
        
        # Robot parameters
        self.max_speed = 0.5
        self.max_turn_speed = 1.0
    
    def gps_callback(self, msg):
        # Update vehicle position from GPS (Odometry data)
        self.current_position = (msg.pose.pose.position.x, msg.pose.pose.position.y)
        quaternion = (
            msg.pose.pose.orientation.x,
            msg.pose.pose.orientation.y,
            msg.pose.pose.orientation.z,
            msg.pose.pose.orientation.w
        )
        euler = self.quaternion_to_euler(quaternion)
        self.current_orientation = euler[2]  # yaw angle
    
    def lidar_callback(self, msg):
        # Update lidar data
        self.lidar_data = msg.ranges
    
    def quaternion_to_euler(self, quat):
        # Convert quaternion to euler angles
        x, y, z, w = quat
        roll = math.atan2(2.0 * (w * x + y * z), 1.0 - 2.0 * (x * x + y * y))
        pitch = math.asin(2.0 * (w * y - z * x))
        yaw = math.atan2(2.0 * (w * z + x * y), 1.0 - 2.0 * (y * y + z * z))
        return roll, pitch, yaw

    def compute_control_commands(self):
        # Compute the control commands based on goal position and lidar data
        
        # Calculate the distance and angle to the goal
        dx = self.goal_position[0] - self.current_position[0]
        dy = self.goal_position[1] - self.current_position[1]
        distance_to_goal = math.sqrt(dx**2 + dy**2)
        angle_to_goal = math.atan2(dy, dx)
        
        # Control the steering using a PID controller
        angle_error = self.normalize_angle(angle_to_goal - self.current_orientation)
        
        self.integral += angle_error
        derivative = angle_error - self.prev_error
        steering_command = self.kp * angle_error + self.ki * self.integral + self.kd * derivative
        self.prev_error = angle_error
        
        # Adjust speed based on distance to goal
        speed_command = min(self.max_speed, distance_to_goal)
        
        # Avoid obstacles by checking lidar data
        for i, distance in enumerate(self.lidar_data):
            if distance < 1.0:  # If an obstacle is detected within 1 meter
                # Avoid the obstacle by turning away
                if i < len(self.lidar_data) // 2:
                    steering_command += 0.5  # Turn right
                else:
                    steering_command -= 0.5  # Turn left
                speed_command = max(0.1, speed_command)  # Slow down if obstacle detected
        
        # Ensure the steering and speed commands are within the limits
        steering_command = max(-self.max_turn_speed, min(self.max_turn_speed, steering_command))
        speed_command = max(0, min(self.max_speed, speed_command))
        
        return steering_command, speed_command

    def normalize_angle(self, angle):
        # Normalize the angle to the range [-pi, pi]
        while angle > math.pi:
            angle -= 2 * math.pi
        while angle < -math.pi:
            angle += 2 * math.pi
        return angle
    
    def drive(self):
        rate = self.create_rate(10)  # 10 Hz
        while rclpy.ok():
            steering, speed = self.compute_control_commands()
            
            # Create the Twist message to publish the control commands
            cmd_msg = Twist()
            cmd_msg.linear.x = speed
            cmd_msg.angular.z = steering
            self.cmd_pub.publish(cmd_msg)
            
            # Sleep to maintain the loop rate
            rate.sleep()

def main():
    rclpy.init()
    vehicle = AutonomousVehicle()
    vehicle.drive()
    rclpy.spin(vehicle)

if __name__ == '__main__':
    main()

