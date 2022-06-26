# 16953 A -> B

import sys
input = sys.stdin.readline
A, B = map(int, input().split())
count = 1

# B를 수정하면서 A로 만들어가기
while True:
    if A == B:
        break
    # A가 B보다 크거나 B가 2로나눠지지않고 10으로 나눈 나머지가 1이아닐때
    elif A > B or (B % 10 != 1 and B % 2 != 0):
        count = -1
        break
    # B가 10으로 나눴을때 나머지가 1이라면
    elif B % 10 == 1:
        B //= 10
        count += 1
    # B가 2로 나눠지면
    elif B % 2 == 0:
        B //= 2
        count += 1

print(count)