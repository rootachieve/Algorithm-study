n = int(input())
d = [0]+list(map(int,input().split()))+[0]
lis = [0]*(n+2)
lds = [0]*(n+2)


for i in range(1,n+1):
    lis[i] = 1
    for j in range(1,i):
        if d[j]<d[i]:
            lis[i] = max(lis[j]+1,lis[i])

for i in range(n,0,-1):
    lds[i] = 1
    for j in range(i+1,n+1):
        if d[j]<d[i]:
            lds[i] = max(lds[j]+1,lds[i])
            
dp = [i+d-1 for i,d in zip(lis,lds)]
print(max(dp))