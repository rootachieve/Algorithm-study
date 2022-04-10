# 1238 파티 (다익스트라)

import sys
import heapq # 우선순위 큐

input = sys.stdin.readline

INF = int(1e9)
N, M, X = map(int, input().split())
arr = [[] for _ in range(N+1)]

for i in range(M):
    start, end, T = map(int, input().split())
    arr[start].append((end, T)) # end로 가는 시간 T, start에 연결

#print(arr)
#==========================================================================

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance = [INF] * (N+1)
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)
        # print(dist, now)
        if distance[now] < dist:
            continue
        # 연결된 노드 확인
        for i in arr[now]:
            cost = dist + i[1]
            # 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧으면 갱신
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    return distance

#==================================================================================

result = 0

for i in range(1, N+1):
    go = dijkstra(i)
    back = dijkstra(X)
    print(go, back)
    result = max(result, go[X] + back[i]) # 파티장소 X로 가는 시간 + X에서 i로 돌아가는 시간
print(result)