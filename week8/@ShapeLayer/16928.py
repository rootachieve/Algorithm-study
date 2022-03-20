from sys import stdin

gets = stdin.readline

n, m = map(int, gets().split())
g = [i for i in range(101)]
res = [-1] * 101

for i in range(n + m):
    x, y = map(int, gets().split())
    g[x] = y

q = []
res[1] = 0
q += [1]
while q:
    x = q.pop(0)
    for i in range(1, 7):
        y = x + i
        if (y > 100):
            continue
        y = g[y]
        if res[y] == -1 or res[y] > res[x] + 1:
            res[y] = res[x] + 1
            q += [y]

print(res[-1])