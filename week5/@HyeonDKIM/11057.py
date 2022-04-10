# 11057 오르막 수 s1

N = int(input())

dp = [[1]*10 for _ in range(N)]

# 점화식: dp[i][j] = dp[i][j-1]+dp[i-1][j]

for i in range(N):
    for j in range(1, 10):
        dp[i][j] = (dp[i][j-1]+dp[i-1][j])%10007

print(dp[N-1][9])
