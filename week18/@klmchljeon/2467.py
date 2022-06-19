#용액

import sys
input = sys.stdin.readline

n = int(input())
d = list(map(int,input().split()))

result = 2000000001
left = 0
right = n-1
syn = []
while left < right:
    s = d[left] + d[right]
    if abs(s) < abs(result):
        syn = [d[left], d[right]]
        result = sum(syn)
    elif s < 0:
        left += 1
    elif s > 0:
        right -= 1
    else:
        print(*syn)
        exit(0)

print(*syn)