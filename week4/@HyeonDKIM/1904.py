# 1904 01타일

N = int(input())

# 점화식 dp[i] = dp[i-1]+dp[i-2]

dp = [0]*(N+1)
dp[1] = 1
if N == 1:
    print(dp[1])
else:
    dp[2] = 2
    for i in range(3, N+1):
        dp[i] = (dp[i-1]+dp[i-2]) % 15746
    print(dp[N])