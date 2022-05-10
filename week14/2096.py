n = int(input())
d = [[[0,0,0] for __ in range(2)] for _ in range(2)]

s = list(map(int,input().split()))
for i in range(2):
    for j in range(2):
        d[i][j] = s[:]

def m(k,m):
    t = [0,2] if k==0 else [0,3] if k==1 else [1,3]
    result = d[0][m][t[0]:t[1]]
    return max(result) if m==0 else min(result)

for _ in range(n-1):
    s = list(map(int,input().split()))
    for mum in range(2):
        for k in range(3):
            d[1][mum][k] = s[k] + m(k,mum)
    
    for i in range(2): d[0][i] = d[1][i][:]

print(m(1,0),m(1,1))