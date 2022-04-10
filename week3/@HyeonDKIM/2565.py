# 2565 전깃줄
# dp, 이분탐색 -> LIS
# 전기줄 개수 - 최장증가부분수열 개수

N = int(input())
line = []

ans = 0

for i in range(N):
    a, b = map(int, input().split())
    line.append([a,b])

# 입력받기 완료 =====================

line.sort() # A 기준 정렬


# LIS - DP
dp = [1]*N # dp 초기화
for i in range(N):
    for j in range(i): # i보다 작은 인덱스들 탐색
        if line[j][1] < line[i][1]:
            # i의 B 전깃줄이 j의 B 전깃줄보다 클 때 최장증가수열 ++
            # 기존 dp[i]값과  dp[j]에 전깃줄 추가했을 때의 max값 구하기
            dp[i] = max(dp[i], dp[j]+1)

ans = N - max(dp)


#LIS - 이분탐색
import bisect

dp = []
dp.append(int(line[0][1]))# 첫번째 수 넣어주기

for i in range(N):
    if line[i][1] > dp[-1]: # dp에 저장된 수보다 크면 그냥 넣어줌
        dp.append(line[i][1])
    else:
        index = bisect.bisect_left(dp, line[i][1]) # 날먹 이분탐색 내장
        dp[index] = line[i][1] # 내장 이분탐색 함수로 찾은 곳에 넣어줌

ans = N - len(dp)

print(ans)