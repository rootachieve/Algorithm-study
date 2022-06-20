import heapq
from sys import stdin

input = stdin.readline
n = int(input())
exams = []
for _i in range(n):
    d, c = map(int, input().split())
    exams.append([d, c])
exams.sort()

q = []
for exam in exams:
    d, c = exam
    heapq.heappush(q, c)
    if d < len(q):
        heapq.heappop(q)
print(sum(q))
