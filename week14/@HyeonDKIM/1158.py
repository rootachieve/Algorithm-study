# 1158 요세푸스 문제

from collections import deque

N, K = map(int, input().split())

q = deque()

for i in range(1, N+1):
    q.append(i)

#print(q)

tmp = 0

print("<", end="")
for i in range(len(q)):
    tmp = tmp + (K-1)
    while tmp >= len(q): # q 길이보다 길어지면 다시 줄여줌
        tmp = tmp % len(q)
    a = q[tmp]
    print(a, end = "")

    if i != N-1:
        print(", ", end = "")
    else:
        print(">", end="")
    q.remove(a)

