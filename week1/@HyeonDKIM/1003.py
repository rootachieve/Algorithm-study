# 1003 피보나치 함수

dp = [0]*41 # 40 이하의 자연수 or 0이므로
dp[0] = 1
dp[1] = 1

# C++함수 파이썬 함수로 변환 =======================
# 추가: dp로 변환
def fibonacci(n):
    if dp[n] == 0:
        dp[n] = fibonacci(n-1) + fibonacci(n-2)
    return dp[n]
# ================================================

T = eval(input())

for i in range(T):
    N = eval(input())
    fibonacci(N)
    if N == 0:
        print(dp[0], 0)
    elif N == 1:
        print(0, dp[1])
    else:
        print(dp[N-2], dp[N-1])
