# 2293 동전1
# 시간, 메모리 상 DP일듯
# 표를 그려서 풀었슴

import sys
input = sys.stdin.readline

가치 = []
n, k = map(int, input().split())
dp = [0 for _ in range(k+1)]
dp[0] = 1

for _ in range(n):
    tmp = int(input())
    가치.append(tmp)

print(가치)

for i in 가치:
    for j in range(1, k+1):
        if j - i >= 0:
            dp[j] += dp[j-i]

print(dp[k])