# 2206 벽 부수고 이동하기

import sys
from collections import deque

input = sys.stdin.readline
x_dir = [1, -1, 0, 0]
y_dir = [0, 0, -1, 1]

N, M = map(int, input().split())

arr = []

for _ in range(N):
    arr.append(list(map(int, input().strip())))

def bfs():
    q = deque()
    q.append([0, 0, 1])
    visited = [[[0]* 2 for _ in range(M)] for __ in range(N)] # crash 여부를 포함한 3차리스트
    visited[0][0][1] = 1 # 벽 뚫을 수 있으면 crash 1, 못 뚫으면 0

    while q:
        x, y, crash = q.popleft()
        if x == N-1 and y == M-1:
            return visited[x][y][crash]

        for i in range(4):
            next_x = x + x_dir[i]
            next_y = y + y_dir[i]

            if 0 <= next_x < N and 0 <= next_y < M:
                if arr[next_x][next_y] == 1 and crash == 1: # 벽부수기 ㄱㄴ
                    visited[next_x][next_y][0] = visited[x][y][1] + 1
                    q.append([next_x, next_y, 0])

                elif arr[next_x][next_y] == 0 and visited[next_x][next_y][crash] == 0:
                    visited[next_x][next_y][crash] = visited[x][y][crash] + 1
                    q.append([next_x, next_y, crash])

    return -1

print(bfs())