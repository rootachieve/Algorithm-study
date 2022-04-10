# 9252 LCS2
'''
ACAYKP
CAPCAK
'''

first = [0] + list(input())
second = [0] + list(input())

dp = [["" for _ in range(len(second))] for _ in range(len(first))]

# 그림 참고하여 점화식 만들기
for i in range(1, len(first)):
    for j in range(1, len(second)):
        if first[i] == second[j]:
            dp[i][j] = dp[i-1][j-1] + first[i] # 굳이 뒤로 안찾아가도록
            # 문자 자체를 dp에 넣어줌
        else:
            if len(dp[i - 1][j]) > len(dp[i][j - 1]):
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = dp[i][j - 1]

# 미리보기=======
for i in dp:        # a에서 안쪽 리스트를 꺼냄
    for j in i:    # 안쪽 리스트에서 요소를 하나씩 꺼냄
        print(j, end=' ')
    print()

if len(dp[-1][-1]) == 0:
    print(0)
else:
    print(len(dp[len(first)-1][len(second)-1]))
    print(dp[len(first)-1][len(second)-1])
