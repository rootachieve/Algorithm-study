# 2573 빙산
# 10주차 4963 섬의개수와 유사
from collections import deque
import sys

input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int,input().split())) for _ in range(N)]
x_dir = [-1, 1, 0, 0]
y_dir = [0, 0, -1, 1]

q = deque()
day = 0
check = False # 플래그

def bfs(a,b):
    q.append((a,b))
    while q:
        x,y = q.popleft()
        visited[x][y] = True
        for i in range(4):
            next_x = x + x_dir[i]
            next_y = y + y_dir[i]
            if 0 <= next_x < N and 0 <= next_y < M:
                if graph[next_x][next_y] != 0 and visited[next_x][next_y] == False:
                    visited[next_x][next_y] = True
                    q.append((next_x,next_y))
                elif graph[next_x][next_y] == 0:
                    count[x][y] += 1 # 주변 0인 것 세주기
    return 1


while True:
    visited = [[False] * M for _ in range(N)]
    count = [[0] * M for _ in range(N)]
    result = []
    for i in range(N):
        for j in range(M):
            if graph[i][j] != 0 and visited[i][j] == False: # 0아닌곳에서 bfs
                result.append(bfs(i, j))
    # 빙산 녹음
    for i in range(N):
        for j in range(M):
            graph[i][j] -= count[i][j] # 아까 센 카운트 빼주기
            if graph[i][j] < 0:
                graph[i][j] = 0

    if len(result) == 0:  # 빙산 분리안될때
        break
    if len(result) >= 2:  # 빙산 분리될때
        check = True
        break
    day += 1

if check:
    print(day)
else:
    print(0)