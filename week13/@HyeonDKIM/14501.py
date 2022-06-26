# 14501 퇴사

N = int(input())

t = [list(map(int, input().split())) for i in range(N)]
dp = [0 for _ in range(N+1)]

for i in range(N-1, -1, -1): # 뒤에서부터 계산, N일 넘어가면 일을 더 못함
    if i + t[i][0] > N: # 일수 넘어가는지?
        dp[i] = dp[i+1]
    else: # 현재 일 보상 + 현재 일 끝난 다음날 보상 / 일 안맡은 보상 비교
        dp[i] = max(t[i][1] + dp[i+t[i][0]], dp[i+1])

print(dp[0])