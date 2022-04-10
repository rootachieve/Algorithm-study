# 1699 제곱수의 합

N = eval(input())
dp = [0]*(N + 1)

for i in range(1, N + 1):
    dp[i] = i # 1부터 N까지 초기화, 1**1들의 개수
    for j in range(1, i):
        if j**2 > i:
            break # 제곱수가 i보다 커질때 끝냄
        if dp[i] > dp[i-j**2] + 1: # min 시간초과;;
            # 예를들어 2**2의 경우, dp[4] -> 4
            # dp[4-2**2] +1 = dp[0]+1 =1
            # 4랑 1 min 했을때 dp[4]는 1로 갱신
            dp[i] = dp[i-j**2] + 1


print(dp[N])
