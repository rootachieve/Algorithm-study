# 4963 섬의개수
import sys
from collections import deque

input = sys.stdin.readline

# 둘러쌓여있으면 섬 -> 8방향
dir_x = [1, -1, 0, 0, 1, -1, 1, -1]
dir_y = [0, 0, -1, 1, -1, -1, 1, 1]

def bfs(i, j):
    arr[i][j] = 0
    q = deque()
    q.append([i, j])
    while q:
        a, b = q.popleft()
        for d in range(8):
            x = a + dir_x[d]
            y = b + dir_y[d]

            if 0 <= x < h and 0 <= y < w and arr[x][y] == 1:
                arr[x][y] = 0 # 방문처리를 바다로 함
                q.append([x, y])

while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    arr = []
    for _ in range(h):
        arr.append(list(map(int, input().split())))

    count = 0
    for i in range(h):
        for j in range(w):
            if arr[i][j] == 1:
                bfs(i, j)
                count +=1
    print(count)