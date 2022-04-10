# 1697 숨바꼭질
import sys
from collections import deque

N, K = map(int, input().split())
sys.setrecursionlimit(10**6)

arr = [0]*100001

def bfs(N):
    q = deque([N])
    while q:
        N = q.popleft()
        if N == K:
            return arr[N]
        for i in (N-1, N+1, N*2):
            if 0 <= i <= 100000 and not arr[i]: # arr[i] false
                arr[i] = arr[N] + 1
                q.append(i)

print(bfs(N))