# 1865 웜홀

# 참고: https://codingexplore.tistory.com/57

import sys

input = sys.stdin.readline
INF = 100000000

def bf(start):
    distance = [INF] * (n+1)
    distance[start] = 0

    for i in range(n):
        for edge in edges:
            cur = edge[0] # 현재 출발 노드
            next_node = edge[1]
            cost = edge[2]

            if distance[next_node] > cost + distance[cur]:
                distance[next_node] = cost + distance[cur]
                if i == n-1:
                    return True
    return False # 음의 사이클 존재시

t = int(input())
for _ in range(t):
    n, m, w = map(int, input().split())
    edges = []

    #도로
    for _ in range(m):
        s, e, t = map(int, input().split())
        edges.append((s, e, t))
        edges.append((e, s, t))

    #웜홀
    for _ in range(w):
        s, e, t = map(int, input().split())
        edges.append((s, e, -t)) # 시간 줄어드므로

    key = bf(1)
    if key:
        print("YES")
    else:
        print("NO")