from sys import stdin
puts = stdin.readline
n, m = map(int, puts().split())
incomes = {i: 0 for i in range(1, n+1)}
graph = {i: [] for i in range(1, n+1)}
res = {i: 0 for i in range(1, n+1)}

# Input Values
for _ in range(m):
    pre, nxt = map(int, puts().split())
    incomes[nxt] += 1
    graph[pre] += [nxt]

# Init Queue
queue = []
for i in range(1, n+1):
    if incomes[i] == 0:
        queue += [i]
        res[i] = 1

while queue:
    now = queue.pop(0)
    for i in graph[now]:
        incomes[i] -= 1
        res[i] = max(res[now], res[now] + 1) # previous가 두 개 이상이어도 알아서 처리됨(아마?)
        if incomes[i] == 0:
            queue += [i]

print(' '.join(map(str, res.values())))