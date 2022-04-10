# 12865 평범한 배낭

'''
* 냅색

v[i] 는 가치 w[i]는 무게
용량 j 인 배낭에 i번째 물건을 넣을때
dp[i][j] = dp[i-1][j-w[i]] + v[i]

가치가 더 큰 것을 찾아야 하니까
max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]) # 넣지 않았을 때와 비교하기

===================================================================
'''

N, K = map(int, input().split())

arr = [[0, 0]] # 첫 배열 초기화, dp 점화식의 i-1 대비
dp = [[0]*(K+1) for _ in range(N+1)]

for i in range(N):
    arr.append(list(map(int, input().split())))

#print(arr)

for i in range(1, N+1):
    for j in range(1, K+1):
        w = arr[i][0]
        v = arr[i][1]
        if j < w:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v)
#print(dp)
print(dp[N][K])