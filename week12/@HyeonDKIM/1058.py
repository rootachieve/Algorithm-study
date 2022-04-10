# 1058 친구

import sys

input = sys.stdin.readline

# 누군가를 거쳐야 하므로 플로이드 와샬

N = int(input())
graph = []
for i in range(N):
    graph.append(list(input()))

visited = [[0] * N for _ in range(N)]

def floyd():
    for k in range(N):
        for i in range(N):
            for j in range(N):
                if i == j:
                    continue
                if graph[i][j] == 'Y' or(graph[i][k] =='Y' and graph[k][j] == 'Y'):
                    visited[i][j] = 1

floyd()
result = 0
for i in range(N):
    count = 0
    for j in range(N):
        if visited[i][j] == 1:
            count += 1
    result = max(result, count)

print(result)