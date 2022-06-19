#센서

n = int(input())
k = int(input())
d = list(map(int,input().split()))
d.sort()

dis = []
for i in range(1,n):
    dis.append(d[i]-d[i-1])

dis.sort()
print(sum(dis)-sum(dis[n-k:]))