# 21922 학부 연구생 민상
from collections import deque
import sys

N, M = map(int, sys.stdin.readline().split()) # 시간초과 ㅋㅋ
q = deque()
grid = []

visited = [[False for _ in range(M)] for _ in range(N)]

for a in range(N):
    tmp = list(map(int, sys.stdin.readline().split()))
    for b in range(M):
        if tmp[b] == 9: # 에어컨을 만나면 큐에 삽입
            q.append((a, b, [0, 1, 2, 3])) # 방향까지
            visited[a][b] = True
    grid.append(tmp)

# 입력 끝===============
#print(grid)
#print(q)
#print(visited)

if q: # 에어컨이 하나라도 있으면
    x_dir = [-1, 1, 0, 0]
    y_dir = [0, 0, -1, 1]

    while q:
        x, y, xy = q.pop() # x, y, 방향
        #print(q)
        for i in xy:
            next_x = x + x_dir[i]
            next_y = y + y_dir[i]

            # n, m 을 넘으면 종료
            while next_x < N and next_y < M and next_x >= 0 and next_y >= 0:
                # 물건 만날 시 처리
                #print("x:", next_x)
                #print("y:", next_y)
                if grid[next_x][next_y] == 0:
                    rotation = [0, 1, 2, 3]
                if grid[next_x][next_y] == 1: # 1번 물건
                    rotation = [0, 1, 3, 2]
                if grid[next_x][next_y] == 2: # 2번 물건
                    rotation = [1, 0, 2, 3]
                if grid[next_x][next_y] == 3:
                    rotation = [3, 2, 1, 0]
                if grid[next_x][next_y] == 4:
                    rotation = [2, 3, 0, 1]
                if grid[next_x][next_y] == 9: # 또다른 에어컨 만나면 그만
                    # 그 에어컨에서 또 해줄것이기 때무네
                    break

                # visited true로 방문표시
                visited[next_x][next_y] = True

                # 바람 방향 변경해주기
                i = rotation[i]

                #다음 while을 위해 한번 더 x, y dir을 더해준다~
                next_x = next_x + x_dir[i]
                next_y = next_y + y_dir[i]

    count = 0
    for a in range(N):
        for b in range(M):
            if visited[a][b] == True:
                count += 1

    print(count)



else:
    print(0)
