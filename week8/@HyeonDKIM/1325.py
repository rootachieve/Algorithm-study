# 1325 효율적인 해킹
import sys
from collections import deque

# pypy
# 나만 이상한거 아니고 python3 맞았습니다가 아무도 없었음;;;;

input = sys.stdin.readline
N, M = map(int, input().split())

arr = [[]for _ in range(N+1)]

for _ in range(M):
    a, b = map(int, input().split())
    arr[b].append(a)

print(arr)
# bfs

def bfs(n):
    count = 1
    visited = [0 for _ in range(N+1)]
    visited[n] = 1
    q = deque()
    q.append(n)
    while q:
        a = q.popleft()
        for i in arr[a]:
            if not visited[i]:
                visited[i] = 1
                count += 1
                q.append(i)
    return count

ans = 0
anslist = []

for i in range(1, N+1):
    if arr[i]:
        tmp = bfs(i) # arr[i]값이 있는것만 계산하도록
        if ans <= tmp: # max값 비교
            if ans < tmp:
                anslist = [] # max값이 갱신되면 리스트도 갱신
            ans = tmp # max값 갱신 적용
            anslist.append(i)

print(*anslist) # 원소들 일괄출력