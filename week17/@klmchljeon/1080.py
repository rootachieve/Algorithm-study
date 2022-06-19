#행렬

n,m = map(int,input().split())

d = []
ans = []

for _ in range(n):
    d.append(list(input()))

for _ in range(n):
    ans.append(list(input()))

def reverse(x,y):
    for i in range(x,x+3):
        for j in range(y,y+3):
            d[i][j] = '1' if d[i][j]=='0' else '0'

cnt = 0
for i in range(n-2):
    for j in range(m-2):
        if d[i][j] != ans[i][j]:
            reverse(i,j)
            cnt += 1

for i in range(n):
    for j in range(m):
        if d[i][j] != ans[i][j]:
            print(-1)
            exit(0)
print(cnt)