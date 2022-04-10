# 11723 집합

import sys

input = sys.stdin.readline
T = int(input())
ans = 0

# 메모리 절약 -> 비트마스킹

for _ in range(T):
    s = input().split()

    # 쉬프트연산 -> 해당 자리로 이동하기
    if s[0] == "add":
        ans |= 1<<int(s[1]) # or로 1이여도 1, 0이여도 1
    elif s[0] == "remove":
        ans &= ~(1<<int(s[1])) # 반전시키고 and 연산

    elif s[0] == "check":
        if ans & (1<<int(s[1])): # and 연산으로 1인지 확인가능
            print(1)
        else:
            print(0)
    elif s[0] == "toggle":
        ans ^= (1<<int(s[1])) # ^로 반전
    elif s[0] == "all":
        ans = (1<<21)-1 # 모든 비트 1로 바꾸면 됨, 싹 밀어버리고 1빼기
    elif s[0] == "empty":
        ans = 0
