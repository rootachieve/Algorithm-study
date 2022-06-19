#미니 버킷 리스트

mod = 1000000007

n,k = map(int,input().split())
r = k - sum(list(map(int,input().split())))

result = 1
for i in range(r+1,n+r+1):
    result = (result*i)%mod

print(result)

'''
n,k=map(int,input().split())
k-=sum(map(int,input().split()))
r=1
for i in range(n):r=r*(k+i+1)%1000000007
print(r)
'''