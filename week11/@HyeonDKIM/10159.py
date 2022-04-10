# 10159 저울

import sys
input = sys.stdin.readline
INF = int(1e9)

N = int(input()) # 물건의 개수 (노드의 개수)
M = int(input()) # 물건 쌍의 개수 (간선의 개수)

graph = [[INF] * (N+1) for _ in range(N+1)]

# 본인 스스로는 0임을 꼭 처리해줘야했음 ㅅㅂ ㅅㅂ
for a in range(1, N+1):
    for b in range(1, N+1):
        if a == b:
            graph[a][b] = 0

for _ in range(M):
    a, b = map(int, input().split())
    graph[a][b] = 1 # 노드끼리 연결

#print(graph)

# 플로이드 와샬
# a -> b 거리보다 a -> k -> n 거리가 더 짧은지?
for k in range(1, N+1):
    for a in range(1, N+1):
        for b in range(1, N+1):
            graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]) # 거리 측정
'''
for i in graph:
    for j in i:
        print(j, end=" ")
    print()
'''
for a in range(1, N+1):
    count = 0
    for b in range(1, N+1):
        if graph[a][b] == INF and graph[b][a] == INF: # a, b가 둘다 INF이면 비교불가능
            count += 1

    print(count)
