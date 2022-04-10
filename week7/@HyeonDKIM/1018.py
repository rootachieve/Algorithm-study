# 1018 체스판 다시 칠하기

N, M = map(int, input().split())
chess = []

for i in range(N):
    chess.append(input())

# print(chess)
# 브루트포스? 걍 개무식하게 조져봐?
tmp = []

for a in range(N-7):
    for b in range(M-7):
        n1 = 0
        n2 = 0
        for i in range(a, a+8):
            for j in range(b, b+8):
                if (i+j) % 2 == 0: # 체스판 짝수는 같은색, 홀수는 같은색
                    if chess[i][j] != 'W': n1 += 1
                    if chess[i][j] != 'B': n2 += 1
                else:
                    if chess[i][j] != 'B': n1 += 1
                    if chess[i][j] != 'W': n2 += 1

        tmp.append(n1)
        tmp.append(n2) # 각 경우의 수 최소값 구하기 위해 리스트에 넣어줌

print(min(tmp))