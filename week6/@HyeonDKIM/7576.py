# 7576 틈메이러

from collections import deque

M, N = map(int, input().split())
box = []
q = deque()
date = 0

x_dir = [-1, 1, 0, 0]
y_dir = [0, 0, -1, 1]

for _ in range(N):
    tmp = list(map(int, input().split()))
    box.append(tmp)

for a in range(N):
    for b in range(M):
        if box[a][b] == 1:
            q.append([a, b])
# print(q)
# print(box)
# print(visited)
while q:
    x, y = q.popleft()

    for i in range(4):
        next_x = x + x_dir[i]
        next_y = y + y_dir[i]

        if next_x >= 0 and next_y >= 0 and next_x < N and next_y < M and box[next_x][next_y] == 0:
            box[next_x][next_y] = box[x][y] + 1 # 하루 돌릴때마다 1 더해서 횟수 세기
            q.append([next_x, next_y])

    #print(q)
    print(box)


for i in box:
    for j in i:
        if j == 0:
            print(-1)
            exit(0)
    date = max(date, max(i))

print(date-1)