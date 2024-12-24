import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

import matplotlib.pyplot as plt
import numpy as np
import math
from shapely.geometry import Polygon

from midterm_msgs.msg import SimpleGPS, SimpleLidar, WallList, Goal, Wall, Control
from std_msgs.msg import Bool


def angle_mod(x, zero_2_2pi=False, degree=False):

    if isinstance(x, float):
        is_float = True
    else:
        is_float = False

    x = np.asarray(x).flatten()
    if degree:
        x = np.deg2rad(x)

    if zero_2_2pi:
        mod_angle = x % (2 * np.pi)
    else:
        mod_angle = (x + np.pi) % (2 * np.pi) - np.pi

    if degree:
        mod_angle = np.rad2deg(mod_angle)

    if is_float:
        return mod_angle.item()
    else:
        return mod_angle

##############################################################
##
## 차량 class
## 차량의 크기, 현재 속도, 위치, 상태 등
##
##############################################################
class Car:
    
    ##############################################################
    ## class 초기화
    ##############################################################
    def __init__(self):
        # 차량 파라미터
        self.LENGTH = 4.5  # [m]
        self.WIDTH = 2.0  # [m]
        self.BACKTOWHEEL = 1.0  # [m]
        self.WHEEL_LEN = 0.3  # [m]
        self.WHEEL_WIDTH = 0.2  # [m]
        self.TREAD = 0.7  # [m]
        self.WB = 2.5  # [m]
        self.MAX_STEER = np.deg2rad(45.0)  # maximum steering angle [rad]
        self.MAX_DSTEER = np.deg2rad(30.0)  # maximum steering speed [rad/s]
        self.MAX_SPEED = 30.0 / 3.6  # maximum speed [m/s]
        self.MIN_SPEED = -20.0 / 3.6  # minimum speed [m/s]
        self.MAX_ACCEL = 1.0  # maximum accel [m/ss]

        # 제어 파라미터
        self.INPUT_a_NOISE = 1.0
        self.INPUT_s_NOISE = np.deg2rad(10.0)

        # LiDAR 파라미터
        self.ANGLE = 10
        self.MAX_DISTANCE = 20

        # GPS 파라미터
        self.GPS_NOISE = 0.5**2

        # 현재 state
        self.current_x = 0.0
        self.current_y = 0.0
        self.current_yaw = 0.0
        self.current_v = 0.0
        
        self.current_center = [0.0, 0,0]

        # 센서
        self.gps1 = [0.0, 0.0] # x, y
        self.gps2 = [0.0, 0.0] # x, y
        self.lidar_raw = [] # [origin_x, origin_y, end_x, end_y, distance] * num_beams
        self.lidar = [] # [distance] * num_beams

    
    ##############################################################
    ## 속도에 따른 state 업데이트
    ##############################################################
    def update_state(self, accel, steering, env):

        # input check
        if steering >= self.MAX_STEER:
            steering = self.MAX_STEER
        elif steering <= -self.MAX_STEER:
            steering = -self.MAX_STEER

        if accel != 0.0:
            accel = accel + self.INPUT_a_NOISE * np.random.randn(1)[0]
        if steering != 0.0:
            steering = steering + self.INPUT_s_NOISE * np.random.randn(1)[0]

        self.current_x = self.current_x + self.current_v * math.cos(self.current_yaw) * env.DT
        self.current_y = self.current_y + self.current_v * math.sin(self.current_yaw) * env.DT
        self.current_yaw = self.current_yaw + self.current_v / self.WB * math.tan(steering) * env.DT
        self.current_v = self.current_v + accel * env.DT

        if self.current_v > self.MAX_SPEED:
            self.current_v = self.MAX_SPEED
        elif self.current_v < self.MIN_SPEED:
            self.current_v = self.MIN_SPEED

        self.update_center()
        self.update_lidar(env)
        self.update_GPS()

    ##############################################################
    ## 충돌 업데이트
    ##############################################################
    def update_collision(self, env):
        if self.check_collision_vehicle(env):
            print("충돌 : ", env.num_collision)

            env.num_collision += 1
            self.current_x = self.current_x - 2 * math.cos(self.current_yaw)
            self.current_y = self.current_y - 2 * math.sin(self.current_yaw)
            self.current_yaw = self.current_yaw
            self.current_v = 0          

            env.publish_collision(True)

            self.update_center()
            self.update_lidar(env)
            self.update_GPS()
            #env.rate.sleep()

        else:
            env.publish_collision(False)

    ##############################################################
    ## 장애물과의 충돌 체크
    ##############################################################
    def check_collision_vehicle(self, env):
        obstacle_list = env.obstacle_list

        # check collision with obstacle
        for o in obstacle_list:
            x_size = o[2]
            y_size = o[3]
            self.o_corners = np.array([[o[0], o[1]], [o[0]+x_size, o[1]], [o[0]+x_size, o[1]+y_size], [o[0], o[1]+y_size]])

            if self.check(self.v_rotated_corners, self.o_corners):
                return True

        return False
            

    def check(self, corners_1, corners_2):
        polygon_1 = Polygon(corners_1)
        polygon_2 = Polygon(corners_2)
        return polygon_1.intersects(polygon_2)
    
    ##############################################################
    ## center
    ##############################################################
    def update_center(self):
        c_to_w = self.LENGTH/2 - self.BACKTOWHEEL
        c_x = self.current_x + c_to_w * np.cos( angle_mod(self.current_yaw) )
        c_y = self.current_y + c_to_w * np.sin( angle_mod(self.current_yaw) )
        self.current_center = [c_x, c_y]

        v_corners = np.array([[-self.LENGTH/2, -self.WIDTH/2], [self.LENGTH/2, -self.WIDTH/2], [self.LENGTH/2, self.WIDTH/2], [-self.LENGTH/2, self.WIDTH/2]])
        rotation_matrix = np.array([[np.cos(angle_mod(self.current_yaw)), -np.sin(angle_mod(self.current_yaw))], [np.sin(angle_mod(self.current_yaw)), np.cos(angle_mod(self.current_yaw))]])
        self.v_rotated_corners = np.dot(v_corners, rotation_matrix.T) + self.current_center


    ##############################################################
    ## Lidar
    ##############################################################
    def update_lidar(self, env):
        self.lidar_raw = []
        self.lidar = []

        angles = np.arange(0, 360, self.ANGLE)

        origin_x = self.current_x
        origin_y = self.current_y

        for angle in angles:
            rad = np.radians(angle)
            end_x = origin_x + self.MAX_DISTANCE * np.cos( angle_mod(self.current_yaw+rad) )
            end_y = origin_y + self.MAX_DISTANCE * np.sin( angle_mod(self.current_yaw+rad) )

            x, y, d = self.check_collision_lidar(origin_x, origin_y, end_x, end_y, env.obstacle_list)

            self.lidar_raw.append([origin_x, origin_y, x, y, d])
            self.lidar.append(d)


    def check_collision_lidar(self, x1, y1, x2, y2, obstacle_list):
        # 직선과 사각형의 충돌을 감지하고, 충돌 지점을 반환
        num_points = 500 
        for t in np.linspace(0, 1, num_points):
            x = x1 + t * (x2 - x1)
            y = y1 + t * (y2 - y1)

            find_flag = False
            out_x, out_y, out_d = x2, y2, np.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
            for o in obstacle_list:
                rect_x = o[0]
                rect_y = o[1]
                rect_size_x = o[2]
                rect_size_y = o[3]

                if rect_x <= x <= rect_x + rect_size_x and rect_y <= y <= rect_y + rect_size_y:
                    find_flag = True
                    if np.sqrt((x - x1) ** 2 + (y - y1) ** 2) < out_d:
                        out_x, out_y, out_d = x, y, np.sqrt((x - x1) ** 2 + (y - y1) ** 2)
            
            if find_flag:
                return out_x, out_y, out_d

        return x2, y2, np.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)


    ##############################################################
    ## GPS
    ##############################################################
    def update_GPS(self):
        GPS_x = self.current_x + self.GPS_NOISE * np.random.randn(1)[0]
        GPS_y = self.current_y + self.GPS_NOISE * np.random.randn(1)[0]
        GPS_yaw = self.current_yaw + self.GPS_NOISE * np.random.randn(1)[0]

        self.gps1 = [GPS_x, GPS_y, GPS_yaw]
        self.gps2 = [GPS_x, GPS_y, GPS_yaw]



##############################################################
##
## 주행 환경에 대한 class
## 차량, 장애물, 벽 배치
## plot
## ROS 통신 정의
##
##############################################################
class DrivingEnvironment(Node):

    ##############################################################
    ## class 초기화
    ##############################################################
    def __init__(self):
        super().__init__('DrivingEnvironment')
        
        # parameter
        self.GOAL = (0.0, 0.0)
        self.WINDOW_SIZE = 20
        self.DT = 0.1
        self.LIDAR_VIS_ON = True
        self.VALID_GOAL_DISTANCE = 1.0
        self.OBSTACLE_SPEED = 0.1
        self.GOAL_FILE_PATH = "/home/gyumin/mobility_ws/src/midterm_env/midterm_env/goal.txt"
        self.WALL_FILE_PATH = "/home/gyumin/mobility_ws/src/midterm_env/midterm_env/wall.txt"
        self.OBSTACLE_FILE_PATH = "/home/gyumin/mobility_ws/src/midterm_env/midterm_env/obstacle.txt"

        qos_profile = QoSProfile(depth=10)

        self.rate = self.create_rate(10)

        #topic publishers
        self.gps1_publisher = self.create_publisher(SimpleGPS, '/gps_1', qos_profile)
        self.gps2_publisher = self.create_publisher(SimpleGPS, '/gps_2', qos_profile)
        self.lidar_publisher = self.create_publisher(SimpleLidar, '/lidar', qos_profile)
        self.wall_publisher = self.create_publisher(WallList, '/walls', qos_profile)
        self.goal_publisher = self.create_publisher(Goal, '/goal', qos_profile)
        self.collision_publisher = self.create_publisher(Bool, '/collision', qos_profile)

        self.timer = self.create_timer(self.DT, self.update)
        self.time = 0

        #topic subscriber(velocity)
        self.velocity_subscriber = self.create_subscription(
            Control,
            '/control',
            self.subscribe_vel_msg,
            qos_profile)
        
        # objects
        self.car = Car()
        self.accel = 0.0
        self.steering = 0.0

        self.wall_list = []  # 처음에 생성되는 벽   # left_bottom_x, left_bottom_y, width, height
        self.obstacle_list = [] # 처음에 생성되는 벽 + 나중에 추가되는 장애물   # left_bottom_x, left_bottom_y, width, height, flag
        self.obstacle_initial_list = [] # 처음의 left_bottom_x, left_bottom_y, patrol_x patrol_y

        self.make_environment()

        # count
        self.reach_goal = False
        self.num_collision = 0
        
        # Visualize environment
        self.fig, self.ax = plt.subplots()
        plt.ion()  # Interactive mode for live plotting       


    ##############################################################
    ## 장애물 생성
    ##############################################################
    def make_environment(self):    
        # goal
        with open(self.GOAL_FILE_PATH, "r") as f:
            lines = f.readlines()
            for i in lines:
                data = i.split(",")
                x, y = float(data[0]), float(data[1])
                self.GOAL = (x, y)

        # wall
        with open(self.WALL_FILE_PATH, "r") as f:
            lines = f.readlines()
            for i in lines:
                data = i.split(",")
                x, y, w, h = float(data[0]), float(data[1]), float(data[2]), float(data[3])
                self.wall_list.append([x, y, w, h])
                self.obstacle_list.append([x, y, w, h, 0])
                self.obstacle_initial_list.append([x, y, 0, 0])

        # obstacle
        with open(self.OBSTACLE_FILE_PATH, "r") as f:
            lines = f.readlines()
            for i in lines:
                data = i.split(",")
                x, y, w, h, p_x, p_y = float(data[0]), float(data[1]), float(data[2]), float(data[3]), float(data[4]), float(data[5])
                self.obstacle_list.append([x, y, w, h, 0])
                self.obstacle_initial_list.append([x, y, p_x, p_y])

    ##############################################################
    ## 장애물 업데이트
    ##############################################################
    def update_obstacle(self):
        for i in range(len(self.obstacle_list)):
            if self.obstacle_initial_list[i][2]==0 and self.obstacle_initial_list[i][3]==0:
                continue
            else:
                if self.obstacle_list[i][4] == 0:
                    new_x, new_y = self.move_towards_target(self.obstacle_list[i][0], self.obstacle_list[i][1], self.obstacle_initial_list[i][2], self.obstacle_initial_list[i][3], self.OBSTACLE_SPEED )
                    self.obstacle_list[i] = [new_x, new_y, self.obstacle_list[i][2], self.obstacle_list[i][3], 0]
                    if new_x == self.obstacle_initial_list[i][2] and new_y == self.obstacle_initial_list[i][3]:
                        self.obstacle_list[i][4] = 1
                else:
                    new_x, new_y = self.move_towards_target(self.obstacle_list[i][0], self.obstacle_list[i][1], self.obstacle_initial_list[i][0], self.obstacle_initial_list[i][1], self.OBSTACLE_SPEED )
                    self.obstacle_list[i] = [new_x, new_y, self.obstacle_list[i][2], self.obstacle_list[i][3], 1]
                    if new_x == self.obstacle_initial_list[i][0] and new_y == self.obstacle_initial_list[i][1]:
                        self.obstacle_list[i][4] = 0                    


    def move_towards_target(self, current_x, current_y, target_x, target_y, distance):
        # 목표 지점까지의 거리 계산
        dx = target_x - current_x
        dy = target_y - current_y
        total_distance = math.sqrt(dx**2 + dy**2)
        
        # 목표 지점에 도달할 수 있는 거리보다 작다면
        if total_distance <= distance:
            return target_x, target_y  # 목표 지점에 도달
        
        # 이동할 비율 계산
        ratio = distance / total_distance
        new_x = current_x + dx * ratio
        new_y = current_y + dy * ratio
        
        return new_x, new_y

    ##############################################################
    ## 장애물 plot
    ##############################################################
    def plot_obstacles(self):
        for i in self.obstacle_list:
            rect = plt.Rectangle((i[0], i[1]), i[2], i[3], color='r')  # 빨간 사각형 생성
            self.ax.add_patch(rect)

    ##############################################################
    ## 차량을 plot
    ##############################################################
    def plot_car(self, x, y, yaw, steer=0.0, cabcolor="-r", truckcolor="-k"):  # pragma: no cover

        # 차량의 바디
        outline = np.array([[-self.car.BACKTOWHEEL, (self.car.LENGTH - self.car.BACKTOWHEEL), (self.car.LENGTH - self.car.BACKTOWHEEL), -self.car.BACKTOWHEEL, -self.car.BACKTOWHEEL],
                            [self.car.WIDTH / 2, self.car.WIDTH / 2, -self.car.WIDTH / 2, -self.car.WIDTH / 2, self.car.WIDTH / 2]])

        fr_wheel = np.array([[self.car.WHEEL_LEN, -self.car.WHEEL_LEN, -self.car.WHEEL_LEN, self.car.WHEEL_LEN, self.car.WHEEL_LEN],
                            [-self.car.WHEEL_WIDTH - self.car.TREAD, -self.car.WHEEL_WIDTH - self.car.TREAD, self.car.WHEEL_WIDTH - self.car.TREAD, self.car.WHEEL_WIDTH - self.car.TREAD, -self.car.WHEEL_WIDTH - self.car.TREAD]])

        rr_wheel = np.copy(fr_wheel)

        fl_wheel = np.copy(fr_wheel)
        fl_wheel[1, :] *= -1
        rl_wheel = np.copy(rr_wheel)
        rl_wheel[1, :] *= -1

        Rot1 = np.array([[math.cos(yaw), math.sin(yaw)],
                        [-math.sin(yaw), math.cos(yaw)]])
        Rot2 = np.array([[math.cos(steer), math.sin(steer)],
                        [-math.sin(steer), math.cos(steer)]])

        fr_wheel = (fr_wheel.T.dot(Rot2)).T
        fl_wheel = (fl_wheel.T.dot(Rot2)).T
        fr_wheel[0, :] += self.car.WB
        fl_wheel[0, :] += self.car.WB

        fr_wheel = (fr_wheel.T.dot(Rot1)).T
        fl_wheel = (fl_wheel.T.dot(Rot1)).T

        outline = (outline.T.dot(Rot1)).T
        rr_wheel = (rr_wheel.T.dot(Rot1)).T
        rl_wheel = (rl_wheel.T.dot(Rot1)).T

        outline[0, :] += x
        outline[1, :] += y
        fr_wheel[0, :] += x
        fr_wheel[1, :] += y
        rr_wheel[0, :] += x
        rr_wheel[1, :] += y
        fl_wheel[0, :] += x
        fl_wheel[1, :] += y
        rl_wheel[0, :] += x
        rl_wheel[1, :] += y

        self.ax.plot(np.array(outline[0, :]).flatten(),
                np.array(outline[1, :]).flatten(), truckcolor)
        self.ax.plot(np.array(fr_wheel[0, :]).flatten(),
                np.array(fr_wheel[1, :]).flatten(), truckcolor)
        self.ax.plot(np.array(rr_wheel[0, :]).flatten(),
                np.array(rr_wheel[1, :]).flatten(), truckcolor)
        self.ax.plot(np.array(fl_wheel[0, :]).flatten(),
                np.array(fl_wheel[1, :]).flatten(), truckcolor)
        self.ax.plot(np.array(rl_wheel[0, :]).flatten(),
                np.array(rl_wheel[1, :]).flatten(), truckcolor)
        self.ax.plot(x, y, "*")

        self.ax.plot(self.car.current_center[0], self.car.current_center[1], "*")


        # Lidar
        if self.LIDAR_VIS_ON:
            for idx, beam in enumerate(self.car.lidar_raw):
                if idx == 0:
                    self.ax.plot([beam[0], beam[2]], [beam[1], beam[3]], 'r', alpha=0.5)
                else:
                    self.ax.plot([beam[0], beam[2]], [beam[1], beam[3]], 'b', alpha=0.5)


    ##############################################################
    ## 주행환경을 시각화
    ##############################################################
    def visualize(self):
        self.ax.clear()
        self.ax.set_xlim(0, self.WINDOW_SIZE)
        self.ax.set_ylim(0, self.WINDOW_SIZE)

        # draw obstacles
        self.plot_obstacles()

        # Draw goal
        self.ax.plot(self.GOAL[0], self.GOAL[1], 'gx')

        # Draw vehicle
        x = self.car.current_x
        y = self.car.current_y
        yaw = self.car.current_yaw
        s = self.steering
        self.plot_car( x, y, yaw, s )

        car_rect = plt.Polygon(self.car.v_rotated_corners , color='b')
        self.ax.add_patch(car_rect)

        plt.title("Time[s]:" + str(round(self.time*self.DT, 2)) + ", speed[km/h]:" + str(round(self.car.current_v * 3.6, 2)))
        self.ax.set_xlim(x - self.WINDOW_SIZE/2, x + self.WINDOW_SIZE/2)  # 창 x축 이동
        self.ax.set_ylim(y - self.WINDOW_SIZE/2, y + self.WINDOW_SIZE/2)  # 창 y축 이동

        plt.grid(True)
        plt.draw()
        plt.pause(0.1)



    ##############################################################
    ## 목표지점에 도달했는지 체크
    ##############################################################
    def check_goal(self):
        distance_to_goal = math.hypot(self.GOAL[0] - self.car.current_x, self.GOAL[1] - self.car.current_y)
        if distance_to_goal < self.VALID_GOAL_DISTANCE:
            self.get_logger().info('Goal reached!')
            self.get_logger().info('num_collision: ' + str(self.num_collision))
            self.get_logger().info('time: ' + str(self.time*self.DT))

            self.destroy_node()


    ##############################################################
    ## 매 time step마다 실행(데이터 publish, 환경 업데이트)
    ##############################################################
    def update(self):
        self.time += 1

        # update obstacle
        self.update_obstacle()

        # update car state
        self.car.update_state(self.accel, self.steering, self)

        # plot
        self.visualize()

        # update collision
        self.car.update_collision(self)

        # plot
        self.visualize()

        # publish
        self.publish_goal()
        self.publish_gps1()
        self.publish_gps2()
        self.publish_lidar()
        self.publish_wall()

        # goal check
        self.check_goal()

    ##############################################################
    ## 토픽 퍼블리시
    ##############################################################
    def publish_gps1(self):
        gps1_msg = SimpleGPS() 
        gps1_msg.x = self.car.gps1[0]
        gps1_msg.y = self.car.gps1[1]
        gps1_msg.yaw = self.car.gps1[2]

        self.gps1_publisher.publish(gps1_msg)

    def publish_gps2(self):
        gps2_msg = SimpleGPS() 
        gps2_msg.x = self.car.gps2[0]
        gps2_msg.y = self.car.gps2[1]
        gps2_msg.yaw = self.car.gps2[2]

        self.gps2_publisher.publish(gps2_msg)

    def publish_lidar(self):
        lidar_msg = SimpleLidar() 
        lidar_msg.beams = self.car.lidar

        self.lidar_publisher.publish(lidar_msg)

    def publish_wall(self):
        wallList_msg = WallList()

        temp = []
        for i in self.wall_list:
            wall_msg = Wall() 
            wall_msg.bl_x = i[0]
            wall_msg.bl_y = i[1]
            wall_msg.size_x = i[2]
            wall_msg.size_y = i[3]

            temp.append(wall_msg)

        wallList_msg.walls = temp

        self.wall_publisher.publish(wallList_msg)

    def publish_goal(self):
        goal_msg = Goal()

        goal_msg.x = self.GOAL[0]
        goal_msg.y = self.GOAL[1]

        self.goal_publisher.publish(goal_msg)

    def publish_collision(self, data):
        collision_msg = Bool()

        collision_msg.data = data

        self.collision_publisher.publish(collision_msg)


    ##############################################################
    ## Control topic에 대한 subscriber. 차량 제어 파라미터를 업데이트
    ##############################################################
    def subscribe_vel_msg(self, msg):
        self.accel = msg.accel
        self.steering = msg.steering



##############################################################
## 메인
##############################################################
def main(args=None):
    rclpy.init(args=args)
    env_node = DrivingEnvironment()

    try:
        rclpy.spin(env_node)
    except KeyboardInterrupt:
        env_node.get_logger().info('Keyboard Interrupt (SIGINT)')
    finally:
        env_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
