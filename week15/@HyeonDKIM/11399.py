# 11399 ATM
# 문제가 길었지만 민망할 정도로 쉬웠던 ,,
N = int(input())
S = list(map(int, input().split()))

#정렬한 다음 빼오면 됨
aaa = 0
S.sort()

for i in range(N):
    for j in range(i + 1):
        aaa += S[j]

print(aaa)