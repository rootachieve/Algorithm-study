# 11497 통나무 건너뛰기

import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    # print(arr)
    arr.sort()

    # 가장 큰 놈을 중앙에
    # 양쪽에 하나씩 세우면서 배치하면 된다
    # 따라서 인덱스 2 차이나는 것들중 최대값을 구하면 댐
    ans = 0
    for i in range(2, N):
        ans = max(ans, abs(arr[i] - arr[i - 2]))
    print(ans)
