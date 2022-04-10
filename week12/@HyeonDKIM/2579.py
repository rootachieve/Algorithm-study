# 2579 계단오르기
import sys

input = sys.stdin.readline

N = int(input())
score = [0 for i in range(301)]
dp = [0 for i in range(301)]

for i in range(N):
    score[i] = int(input())

dp[0] = score[0]
dp[1] = score[0] + score[1]
# 다음 계단 or 다음다음 계단 중 점수 큰 것을 저장함
dp[2] = max(score[1] + score[2], score[0] + score[2])

for i in range(3, N):
    # 마지막 계단의 전 계단을 밟거나 / 밟지 않거나
    dp[i] = max(dp[i-3] + score[i-1] + score[i], dp[i-2] + score[i])
print(dp[N-1])