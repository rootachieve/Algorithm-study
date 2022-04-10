# 1245 농장관리
from collections import deque

# 왜 다 dfs로 푸냐고..

N, M = map(int, input().split())
graph = []
q = deque()
minheight = 500 # 최소높이 설정

# 모든 노드마다 bfs를 해주며 큰 녀석이 인접해 있으면 산봉우리가 아니다
# 같은 녀석은 괜찮음 -> 산봉우리가 이어져 있는 것으로 간주

# 인접 모든 3*3 내의 집합 찾아야 함
x_dir = [-1, 1, 0, 0, -1, -1, 1, 1]
y_dir = [0, 0, -1, 1, -1, 1, -1, 1]

visited = [[False for _ in range(M)] for _ in range(N)]
#print(visited)
for i in range(N):
    tmp = list(map(int, input().split()))
    graph.append(tmp)

for i in range(N):
    for j in range(M):
        minheight = min(minheight, graph[i][j])

#print(graph)
#print(visited)

def bfs(a, b, height):
    global Trigger
    global MtCounter
    global CounTrigger

    Trigger = True
    CounTrigger = False

    q.append((a, b))
    while q:
        x, y = q.popleft()
        for i in range(8):
            next_x = x + x_dir[i]
            next_y = y + y_dir[i]

            if 0 <= next_x < N and 0 <= next_y < M:
                if graph[next_x][next_y] > height:
                    Trigger = False # 더 큰 녀석이 인접해 있으면 얘는 산봉우리 아님
                elif not visited[next_x][next_y] and graph[next_x][next_y] == height:
                    q.append((next_x, next_y)) # 똑같은 녀석은 또 bfs, 큰 녀석 주변에 있나 찾음
                    visited[next_x][next_y] = True

    if Trigger and height > minheight:
        CounTrigger = True
    return CounTrigger
counter = 0

for i in range(N):
    for j in range(M):
        #print((i, j))
        if visited[i][j]: continue
        if bfs(i, j, graph[i][j]):
            counter += 1

print(counter)


'''
첫 시도
# 계속 bfs 돌려서 산봉우리 찾기
# 크기 큰게 나오면 산봉우리 끝으로 간주

2차시도
# 0은 모두 visited로 간주
 -> 틀린건 이때문이 아니였음 ,,, 2가 있는데 1이 먼저 나와서 2가 나오면 산봉우리 끝으로 간주해버림
 다른 해결책 필요 -> 크기 큰게 산봉우리 끝이 아님
 
 3차시도
 그냥 visited True 나오면 그만 가는걸로 하자
 왜냐면 0은 이미 visited True 로 싹 전처리 시켜줬으니까
 
 맞왜틀
 
 
3 3
1 2 1
1 1 1
1 2 1
 
'''