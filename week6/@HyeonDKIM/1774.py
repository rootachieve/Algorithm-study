# 1774 우주신과의 교감
import math

N, M = map(int, input().split())

location = []  # 신들의 위치
root = [i for i in range(N)]  # 루트노드 저장
graph = []  # 간선

for i in range(N):
    tmp1, tmp2 = map(int, input().split())
    location.append([tmp1, tmp2])

# 입력 =============================================

# 유니온파인드 ======================================
def Find(x):
    if root[x] == x:
        return x
    else:
        y = Find(root[x])
        root[x] = y
        return y

def Union(x, y):
    x = Find(x)
    y = Find(y)
    if x != y:
        root[y] = x

# ========================================================

M_count = 0  # 연결된 간선 개수
for _ in range(M):  # 이미 연결된 경우
    god1, god2 = map(int, input().split())
    if Find(god1 - 1) != Find(god2 - 1):  # 연결할수 있다면
        Union(god1 - 1, god2 - 1)
        M_count += 1


# 거리구하기
for i in range(N - 1):
    for j in range(i + 1, N):
        # 각 별간의 거리 계산
        # ( 에이제곱 + 비제곱 )루트
        dis = math.sqrt((location[i][0] - location[j][0]) ** 2 + (location[i][1] - location[j][1]) ** 2)
        graph.append([dis, i, j])

graph.sort()

result = 0
for dis, x, y in graph:
    if Find(x) != Find(y):
        Union(x, y)
        result += dis  # 거리추가
        M_count += 1  # 간선추가
    if M_count == N - 1:  # 간선의 수가 N-1이 되면 멈춘다.
        break

print("%0.2f" % result)  # 두자리까지 출력