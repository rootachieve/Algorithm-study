# 1080 행렬

N, M = map(int, input().split())
A = []
B = []

for i in range(N):
    A.append(list(map(int, input())))
for i in range(N):
    B.append(list(map(int, input())))

def convert(x, y, arr):
    for i in range(x, x+3):
        for j in range(y, y+3):
            if A[i][j] == 0:
                A[i][j] = 1
            else:
                A[i][j] = 0

count = 0

for i in range(0, N-2):
    for j in range(0, M-2):
        if A[i][j] != B[i][j]:
            convert(i, j, A)
            count += 1

flag = False
for i in range(0, N):
    for j in range(0, M):
        if A[i][j] != B[i][j]:
            flag = True

if flag:
    print(-1)
else:
    print(count)