#컵라면

import sys
import heapq
input = sys.stdin.readline

n = int(input())
d = [list(map(int,input().split())) for _ in range(n)]
d.sort()

result = []
for t,val in d:
    heapq.heappush(result,val)
    if t < len(result):
        heapq.heappop(result)
print(sum(result))