# 11437 lca
import sys
sys.setrecursionlimit(10000) # 메모리초과

input = sys.stdin.readline # 시간초과
N = int(input())

depth = [0] * (N+1)
parent = [0] * (N+1)
graph = [[] for _ in range(N+1)]
visited = [0] * (N+1)

for _ in range(N-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(x, d):
    visited[x] = True
    depth[x] = d

    for node in graph[x]:
        if visited[node]:
            continue
        parent[node] = x
        dfs(node, d + 1)

def lca(a, b): # 깊이 리스트에서 부모노드가 어디서 같은지 확인하기
    while depth[a] != depth[b]: # 깊이를 일단 같은 위치로 옮기기
        if depth[a] > depth[b]:
            a = parent[a]
        else:
            b = parent[b]
        #print(a, b)

    while a != b: # 높이가 같아지면 이제 LCA를 찾아주기 위해 계속 갱신
        a = parent[a]
        b = parent[b]
        print(a, b)

    return a

dfs(1, 0)

M = int(input())

for _ in range(M):
    a, b = map(int, input().split())
    print(lca(a, b))
