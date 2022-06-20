from collections import deque
from sys import stdin

input = stdin.readline
for _i in range(int(input())):
    p = input().rstrip()
    n = int(input())
    gets = input()[1:-2]
    err = False
    xn = deque()
    reverse = 0
    if gets: xn = deque(map(int, gets.split(',')))
    for o in p:
        if o == 'R':
            reverse = (reverse + 1) % 2
        elif o == 'D':
            if not xn:
                err = True
                break
            else:
                if not reverse:
                    xn.popleft()
                else:
                    xn.pop()
    if not err:
        if reverse:
            xn.reverse()
        puts = ','.join(map(str, xn))
        print(f'[{puts}]')
    else:
        print('error')
