# 11758 CCW

# 기하와벡터 ?...

import sys
input = sys.stdin.readline

p = []
for _ in range(3):
    p.append(list(map(int, input().split())))

# CCW : (x1y2 + x2y3 + y3x1) - (y1x2 + y2x3 + y3x1)

def ccw(p1, p2, p3):
    return (p1[0]*p2[1] + p2[0]*p3[1] + p3[0]*p1[1]) - (p1[1]*p2[0] + p2[1]*p3[0] + p3[1]*p1[0])

result = ccw(p[0], p[1], p[2])

if result > 0:
    print(1)
elif result == 0:
    print(0)
else:
    print(-1)