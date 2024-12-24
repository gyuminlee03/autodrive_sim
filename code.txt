import rclpy  # ROS2 파이썬 클라이언트 라이브러리
from rclpy.node import Node  # ROS2 노드 클래스
from rclpy.qos import QoSProfile  # QoS 프로파일을 설정하는 클래스
from midterm_msgs.msg import SimpleGPS, SimpleLidar, WallList, Goal, Control  # 사용자 정의 메시지 타입 가져오기

import numpy as np  # 수학적 연산을 위한 numpy 라이브러리
import math  # 수학적 연산을 위한 math 모듈
import matplotlib.pyplot as plt  # 시각화를 위한 matplotlib 라이브러리
from heapq import heappop, heappush  # 우선순위 큐를 사용하기 위한 heapq 라이브러리
from scipy.interpolate import CubicSpline  # 경로 보간을 위한 Cubic Spline 클래스


# 칼만 필터를 이용한 GPS 융합 클래스
class KalmanFilter:
    def __init__(self):
        self.state = np.zeros(3)  # [x, y, yaw] 초기 상태 벡터
        self.covariance = np.eye(3) * 1e-3  # 초기 공분산 행렬 설정

    def predict(self, dt, velocity=0.0, yaw_rate=0.0):
        # 상태 전이 행렬
        F = np.eye(3)
        # 제어 입력 행렬
        B = np.array([
            [math.cos(self.state[2]) * dt, 0],
            [math.sin(self.state[2]) * dt, 0],
            [0, dt]
        ])
        u = np.array([velocity, yaw_rate])  # 제어 입력 (속도와 yaw rate)

        # 상태 예측
        self.state = F @ self.state + B @ u
        # 예측 잡음 공분산 행렬
        Q = np.eye(3) * 0.1
        # 공분산 예측
        self.covariance = F @ self.covariance @ F.T + Q

    def update(self, measurement, noise):
        # 관측 행렬
        H = np.eye(3)
        # 관측 노이즈 공분산 행렬
        R = np.eye(3) * noise

        # 관측 오차 계산
        y = measurement - H @ self.state
        # 오차 공분산
        S = H @ self.covariance @ H.T + R
        # 칼만 이득 계산
        K = self.covariance @ H.T @ np.linalg.inv(S)

        # 상태 갱신
        self.state += K @ y
        # 공분산 갱신
        self.covariance = (np.eye(3) - K @ H) @ self.covariance


# 안전 거리를 고려한 A* 알고리즘을 이용한 경로 계획 함수
def a_star_with_margin(start, goal, walls, grid_size=1.0, margin=1.0):
    def heuristic(a, b):
        # 유클리드 거리 계산 (휴리스틱 함수)
        return math.sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2)

    wall_set = set()
    # 벽과 충돌을 피하기 위해 안전 거리를 고려한 영역을 추가
    for wall in walls:
        x_start = int((wall[0] - margin) / grid_size)
        y_start = int((wall[1] - margin) / grid_size)
        x_end = int((wall[0] + wall[2] + margin) / grid_size)
        y_end = int((wall[1] + wall[3] + margin) / grid_size)
        for x in range(x_start, x_end + 1):
            for y in range(y_start, y_end + 1):
                wall_set.add((x, y))

    start_grid = (int(start[0] / grid_size), int(start[1] / grid_size))  # 시작 점 그리드 좌표
    goal_grid = (int(goal[0] / grid_size), int(goal[1] / grid_size))  # 목표 점 그리드 좌표

    open_set = []  # 열린 리스트 (탐색해야 할 노드)
    heappush(open_set, (0 + heuristic(start_grid, goal_grid), 0, start_grid, None))  # 우선순위 큐에 초기 노드 추가
    came_from = {}  # 이전 노드를 기록하기 위한 딕셔너리
    cost_so_far = {start_grid: 0}  # 각 노드까지의 비용 기록

    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]  # 상하좌우 이동

    while open_set:
        _, cost, current, parent = heappop(open_set)

        if current in came_from:
            continue
        came_from[current] = parent

        if current == goal_grid:
            path = []
            while current:
                path.append((current[0] * grid_size, current[1] * grid_size))  # 실제 좌표로 변환
                current = came_from[current]
            return path[::-1]  # 시작점부터 목표점까지 경로 반환

        # 인접한 노드 탐색
        for dx, dy in directions:
            neighbor = (current[0] + dx, current[1] + dy)
            if neighbor in wall_set or neighbor in cost_so_far:
                continue
            new_cost = cost + heuristic(current, neighbor)
            cost_so_far[neighbor] = new_cost
            priority = new_cost + heuristic(neighbor, goal_grid)
            heappush(open_set, (priority, new_cost, neighbor, current))

    return []  # 경로가 없는 경우 빈 리스트 반환


# Cubic Spline 보간을 이용한 경로 부드럽게 하기
def smooth_path(path, num_points=100):
    if len(path) < 3:
        return path  # 경로가 너무 짧으면 보간하지 않음

    x, y = zip(*path)
    cs_x = CubicSpline(range(len(x)), x)  # x 좌표에 대해 Cubic Spline 보간
    cs_y = CubicSpline(range(len(y)), y)  # y 좌표에 대해 Cubic Spline 보간

    t = np.linspace(0, len(x) - 1, num_points)  # 보간할 점 생성
    smooth_x = cs_x(t)
    smooth_y = cs_y(t)

    return list(zip(smooth_x, smooth_y))  # 부드럽게 보간된 경로 반환


# Pure Pursuit Controller를 이용한 제어
class PurePursuitController:
    def __init__(self, lookahead_distance):
        self.lookahead_distance = lookahead_distance  # 차량의 lookahead 거리 설정
        self.previous_steering = 0.0  # 이전 스티어링 값 초기화
        self.smoothing_factor = 0.3  # 스티어링 값의 부드러움을 위한 스무딩 계수

    def find_target_point(self, path, current_pos):
        # 현재 위치에서 lookahead 거리 이상 떨어진 목표 점 찾기
        for i, point in enumerate(path):
            dist = math.hypot(point[0] - current_pos[0], point[1] - current_pos[1])
            if dist >= self.lookahead_distance:
                return point
        return path[-1]  # 목표 점이 없으면 마지막 점 반환

    def control(self, current_pos, current_yaw, target_point):
        # 목표 점을 향한 스티어링 각도 계산
        alpha = math.atan2(target_point[1] - current_pos[1], target_point[0] - current_pos[0]) - current_yaw
        raw_steering = 2 * math.sin(alpha) / self.lookahead_distance

        # 스티어링 값을 부드럽게 하기 위해 스무딩 적용
        smoothed_steering = (
            self.smoothing_factor * raw_steering +
            (1 - self.smoothing_factor) * self.previous_steering
        )
        self.previous_steering = smoothed_steering
        return smoothed_steering


# 시각화를 위한 클래스
class Visualization:
    def __init__(self):
        self.fig, self.ax = plt.subplots()  # 플롯 초기화
        plt.ion()  # 상호작용 모드 켜기
        plt.show()  # 플롯 보이기

    def update(self, walls, obstacles, path, car_position, goal, lidar_data):
        # 시각화 업데이트
        self.ax.clear()
        self.ax.set_xlim(-10, 100)  # x 축 범위 설정
        self.ax.set_ylim(-10, 100)  # y 축 범위 설정

        # 벽 시각화
        for wall in walls:
            rect = plt.Rectangle((wall[0], wall[1]), wall[2], wall[3], color='gray')
            self.ax.add_patch(rect)

        # 장애물 시각화
        for obs in obstacles:
            self.ax.plot(obs[0], obs[1], 'ro')

        # 경로 시각화
        if path:
            x, y = zip(*path)
            self.ax.plot(x, y, '-g')

        # 차량 위치 시각화
        self.ax.plot(car_position[0], car_position[1], 'bo')

        # 목표 위치 시각화
        if goal:
            self.ax.plot(goal[0], goal[1], 'rx')

        # LiDAR 데이터 시각화
        for beam in lidar_data:
            self.ax.plot([car_position[0], beam[0]], [car_position[1], beam[1]], 'b', alpha=0.5)

        plt.pause(0.1)  # 시각화 업데이트


# 자율 주행 노드 클래스
class AutonomousDrivingNode(Node):
    def __init__(self):
        super().__init__('autonomous_driving_node')
        qos_profile = QoSProfile(depth=10)

        # Publishers and subscribers
        self.control_publisher = self.create_publisher(Control, '/control', qos_profile)
        self.gps1_subscriber = self.create_subscription(SimpleGPS, '/gps_1', self.gps1_callback, qos_profile)
        self.gps2_subscriber = self.create_subscription(SimpleGPS, '/gps_2', self.gps2_callback, qos_profile)
        self.lidar_subscriber = self.create_subscription(SimpleLidar, '/lidar', self.lidar_callback, qos_profile)
        self.wall_subscriber = self.create_subscription(WallList, '/walls', self.wall_callback, qos_profile)
        self.goal_subscriber = self.create_subscription(Goal, '/goal', self.goal_callback, qos_profile)

        # Kalman filter and control logic
        self.kalman_filter = KalmanFilter()
        self.current_pos = [0.0, 0.0]
        self.current_yaw = 0.0
        self.goal = None
        self.walls = []
        self.dynamic_obstacles = []
        self.path = []

        # Pure pursuit and visualization
        self.pure_pursuit = PurePursuitController(lookahead_distance=3.0)
        self.visualization = Visualization()
        self.timer = self.create_timer(0.1, self.control_loop)

    def gps1_callback(self, msg):
        noise = 1.0 if self.kalman_filter.state[0] < 50 else 5.0
        self.kalman_filter.update(np.array([msg.x, msg.y, msg.yaw]), noise)

    def gps2_callback(self, msg):
        noise = 5.0 if self.kalman_filter.state[0] < 50 else 1.0
        self.kalman_filter.update(np.array([msg.x, msg.y, msg.yaw]), noise)

    def lidar_callback(self, msg):
        self.dynamic_obstacles = []
        for i, distance in enumerate(msg.beams):
            if distance < 20.0:
                angle = math.radians(i * 10)
                x = self.current_pos[0] + distance * math.cos(self.current_yaw + angle)
                y = self.current_pos[1] + distance * math.sin(self.current_yaw + angle)
                self.dynamic_obstacles.append((x, y))

    def wall_callback(self, msg):
        self.walls = [[wall.bl_x, wall.bl_y, wall.size_x, wall.size_y] for wall in msg.walls]

    def goal_callback(self, msg):
        self.goal = [msg.x, msg.y]

    def control_loop(self):
        self.kalman_filter.predict(0.1)
        self.current_pos = self.kalman_filter.state[:2]
        self.current_yaw = self.kalman_filter.state[2]

        planning_walls = self.walls
        for obs in self.dynamic_obstacles:
            planning_walls.append([obs[0], obs[1], 1.0, 1.0])

        raw_path = a_star_with_margin(self.current_pos, self.goal, planning_walls, margin=2.0)
        self.path = smooth_path(raw_path, num_points=100)

        self.visualization.update(self.walls, self.dynamic_obstacles, self.path, self.current_pos, self.goal, self.dynamic_obstacles)

        if self.path:
            self.execute_control()

    def execute_control(self):
        if not self.path:
            return

        target_point = self.pure_pursuit.find_target_point(self.path, self.current_pos)
        distance_to_goal = math.hypot(self.goal[0] - self.current_pos[0], self.goal[1] - self.current_pos[1])
        steering_angle = self.pure_pursuit.control(self.current_pos, self.current_yaw, target_point)

        # Dynamic speed control based on proximity to the goal
        if distance_to_goal < 2.0:
            # Near the goal, reduce speed
            speed = -0.5 if distance_to_goal < 0.5 else 0.5  # Reverse if too close
        else:
            # Regular speed
            speed = 1.0

        control_msg = Control()
        control_msg.accel = speed
        control_msg.steering = steering_angle
        self.control_publisher.publish(control_msg)

        # Stop if very close to the goal
        if distance_to_goal < 0.2:
            self.stop_vehicle()

    def stop_vehicle(self):
        # Publish zero acceleration and steering to stop the vehicle
        control_msg = Control()
        control_msg.accel = 0.0
        control_msg.steering = 0.0
        self.control_publisher.publish(control_msg)
        self.get_logger().info("Vehicle has reached the goal and stopped.")


def main(args=None):
    rclpy.init(args=args)
    node = AutonomousDrivingNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
