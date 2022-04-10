# 16928 비얌과 사다리 게임

import sys
input = sys.stdin.readline
from collections import deque

N, M = map(int, input().split())

arr = [0 for _ in range(101)]
visited = [False for _ in range(101)]
ladder = {}
snake = {} # 딕셔너리 응용

# 사다리랑 비얌들 넣어주기
for i in range(N):
    x, y = map(int, input().split())
    ladder[x] = y

for i in range(M):
    u, v = map(int, input().split())
    snake[u] = v

#===============================================
print(ladder)
print(snake)
q = deque()

def bfs(n):
    q.append(n)
    visited[n] = True
    while q:
        a = q.popleft()
        for i in range(1, 7):
            next = a + i
            if 0 < next < 101:
                # 각 딕셔너리에 존재하면
                if next in ladder:
                    next = ladder[next]
                if next in snake:
                    next = snake[next]
                if not visited[next]:
                    q.append(next)
                    visited[next] = True
                    arr[next] = arr[a] + 1 # arr 자체에 값 저장

bfs(1)
print(arr)
print(arr[100])



