# 2229 조 짜기

# 실력 차이 크게
# 잘 짜인 정도 -> 높은점수 - 낮은점수

N = int(input())

arr = [0] + list(map(int, input().split())) # 나이 순으로 정렬해서 줌
dp = [0] * (N+1)

for i in range(1, N+1):
    max = 0
    min = 100000000000000
    
    for j in range(i, 0, -1):
        if max < arr[j]:
            max = arr[j]
        if min > arr[j]:
            min = arr[j]
        if dp[i] < dp[j-1] + max - min:
            dp[i] = dp[j-1] + max - min


print(dp[N])
#print(dp)
