# 리스트로 구현
from sys import stdin
n, m, v = map(int, stdin.readline().split())
dots = dict(enumerate([[] for i in range(n)], start=1))
for _ in range(m):
    a, b = map(int, stdin.readline().split())
    dots[a] += [b]
    dots[b] += [a]
for j in dots:
    dots[j].sort()
v_dfs = []
v_bfs = []

def dfs(n):
    global v_dfs
    v_dfs += [n]
    for dot in dots[n]:
        if dot not in v_dfs:
            dfs(dot)

def bfs(n):
    global v_bfs
    queue = [n]
    i = 0
    while queue:
        dot = queue.pop(0)
        if dot not in v_bfs:
            v_bfs += [dot]
            queue += dots[dot]

dfs(v)
bfs(v)
for _ in v_dfs:
    print(_, end = ' ')
print()
for _ in v_bfs:
    print(_, end = ' ')