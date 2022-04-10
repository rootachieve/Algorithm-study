#1026 보물 -> 파이썬

N = eval(input())

A = input().split()
B = input().split()

for i in range(N):
    A[i] = int(A[i])
    B[i] = int(B[i])
#입력받기----------------------------

S = 0

A.sort()


for i in range(N):
    b = B.pop(B.index(max(B)))
    S = S + A[i]*b
    #print(A[i]*b)

print(S)