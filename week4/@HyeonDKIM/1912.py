# 1912 연속합

n = int(input())

arr = list(map(int, input().split()))
dp = [0]*(len(arr))
# dp 배열 만들어서 연속합을 넣어줌

dp[0] = arr[0]
# dp[0]값 초기화, -값의 경우 0보다 작다고 판단하여 dp 자체에 들어가지 않음;

for i in range(1, len(arr)):
    dp[i] = max(arr[i], dp[i-1]+arr[i])
    # 연속합을 하다가 현재 수가 연속합보다 크면 현재 수로 갱신,
    # 갱신된다면 그 '현재 수' 부터 다시 연속합을 만들어 나감

print(max(dp))