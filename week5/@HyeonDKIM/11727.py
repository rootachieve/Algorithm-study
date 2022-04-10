# 11727 2*n 타일링 2 s3

n = int(input())

# 점화식: dp[i] = dp[i-1]+2*dp[i-2]

dp = [0]*1001
dp[1] = 1
dp[2] = 2

for i in range(3, n+1):
    dp[i] = (dp[i-1] + 2*dp[i-2])%10007

print(dp[n])
