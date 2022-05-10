n = int(input())
seq = list(map(int,input().split()))

d = [[0,0] for i in range(n)] 
d[0][0] = d[0][1] = seq[0]

result = seq[0]
for i in range(1,n):
    d[i][0] = max(d[i-1][0]+seq[i], seq[i])
    d[i][1] = max(d[i-1][0], d[i-1][1]+seq[i])
    result = max(result,d[i][0],d[i][1])
    
print(result)