import heapq

n = int(input())
d = []
for i in range(n):
    s,e = map(int, input().split())
    d.append([s,e])

d.sort()

result = []
heapq.heappush(result, d[0][1])

for i in range(1,n):
    if d[i][0] < result[0]:
        heapq.heappush(result, d[i][1])
    else:
        heapq.heappop(result)
        heapq.heappush(result, d[i][1])

print(len(result))

    