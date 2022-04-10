# 1309 동물원

N = int(input())

dp = [0]*(N+1)
dp[0] = 1 # 사자가 없는 것도 경우로 침
dp[1] = 3

# 점화식 dp[i] = 2*dp[i-1]+dp[i-2]

for i in range(2, N+1):
    dp[i] = (2*dp[i-1] + dp[i-2])%9901 #메모리 초과로 여기서 % 9901 해줌

print(dp[N])