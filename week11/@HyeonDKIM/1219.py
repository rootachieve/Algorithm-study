# 1219 오민식의 고민

import sys
input = sys.stdin.readline
INF = int(1e9)

#벨만포드
N, start, end, M = map(int, input().split())
graph = []
distance = [INF] * (N + 1)

for i in range(M):
    start, end, cost = map(int, input().split())
    graph.append([start, end, cost])

money = list(map(int, input().split()))
print(graph)

def bf(start):
    distance[start] = 0

    for i in range(N):
        for start, end, cost in graph:
            if distance[start] != INF and distance[start] + cost < distance[end]:
                distance[end] = distance[start] + cost
                if i == N - 1:
                    return True
    return False

print(distance)

if bf(0):
    print("Gee")
else:
    print(-distance[end])

# 벨만포드는 이제 머하는건지 대충 알겠음
# 근데 그 돈 리스트랑 어떤 식으로 연결해야 할지 감이 잘 안옴
# 결론 : 아직 풀기엔 내 그릇이 작으므로 여러분의 풀이를 보고 한수 배워가겠음요 ㅠㅠ