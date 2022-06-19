#동전 1

n,k = map(int,input().split())
d = [[0]*(k+1) for _ in range(2)]
d[0][0] = 1

for i in range(n):
    coin = int(input())
    if i & 1 == 0:
        for j in range(k+1):
            if coin > j:
                d[1][j] = d[0][j]
            else:
                d[1][j] = d[0][j] + d[1][j-coin]
    else:
        for j in range(k+1):
            if coin > j:
                d[0][j] = d[1][j]
            else:
                d[0][j] = d[1][j] + d[0][j-coin]

if n & 1 == 0:
    print(d[0][-1])
else:
    print(d[1][-1])
