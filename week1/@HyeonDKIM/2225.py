# 2225 합분해
# 어려우면 표로 그려서 규칙 찾기
N, K = map(int, input().split())

# N+1로하면 ㅈㄴ틀리고 인덱스에러뜸 진자개열받음 전부수정
# dp = [[0]*(N+1) for _ in range(N+1)]
dp = [[0]*201 for _ in range(201)]

# 가로세로주의!!
# 세로가 [앞] 가로가 [뒤] [앞][뒤]

for i in range(201):
    dp[1][i] = 1
    dp[2][i] = i + 1
    dp[i][1] = i
    for j in range(2, 201):
        dp[i][j] = dp[i-1][j] + dp[i][j-1]

# print(dp[K][N])
print(dp[K][N] % 1000000000)
