#AC

import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
for case in range(t):
    q = input()
    n = int(input())
    d = deque(eval(input()))

    r = 0
    for i in q:
        if i == 'R': r^=1; continue

        if i == 'D':
            try: d.popleft() if r==0 else d.pop()
            except: r = 2; break

    if r==2:
        print('error')
    else:
        if r==1: d.reverse()
        print(str(list(d)).replace(' ',''))
