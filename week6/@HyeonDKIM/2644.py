# 2644 촌수계산
from collections import deque

# 촌수계산 -> bfs 1회당 1씩 늘어남
n = int(input())
a, b = map(int, input().split())
m = int(input())
q = deque()
graph = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]
# ==================================================

for i in range(m):
    tmp1, tmp2 = map(int, input().split())
    graph[tmp1].append(tmp2)
    graph[tmp2].append(tmp1)

# 간선 끼리 이어주기 ===================================

q.append((0, a))

def bfs():
    while q:
        x, y = q.popleft()
        visited[y] = True
        for i in graph[y]:
            if not visited[i]:
                q.append((x+1, i))
            if i == b:
                return x+1
    return -1
print(bfs())