n = int(input())
d = list(map(int,input().split()))
s = [0]*n

for i in range(1,n):
    score = max(d[:i+1])-min(d[:i+1])
    for j in range(i,0,-1):
        slice_d = d[j:i+1]
        score = max(score, (s[j-1] + max(slice_d)-min(slice_d)))
    s[i] = score
    
print(s[-1])