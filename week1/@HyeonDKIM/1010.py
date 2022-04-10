# 1010 다리 놓기

T = eval(input())

for t in range(T):
    N, M = input().split()
    N = int(N)
    M = int(M)
    up = 1
    down = 1

# 조합: MCN
    for i in range(N):
        up = up * (M - i)
        down = down * (N - i)

    ans = up//down
    print(ans)