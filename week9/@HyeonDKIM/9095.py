# 9095 1 2 3 더하기
import sys
input = sys.stdin.readline

T = int(input())
arr = []
dp = [1, 2, 4]
# dp[i] = dp[i-3] + dp[i-2] + dp[i-1]

for i in range(3, 10):
    dp.append(dp[i-3] + dp[i-2] + dp[i-1])

for i in range(T):
    a = int(input())
    print(dp[a-1])