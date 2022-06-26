# 9461 파도반 수열

# 1 1 1 2 2 3 4 5 7 9
# i+3 = i + i+1

T = int(input())
arr = [0]*101
arr[1] = 1
arr[2] = 1
arr[3] = 1

for i in range(0, 98):
    arr[i + 3] = arr[i] + arr[i + 1]

for _ in range(T):
    N = int(input())
    print(arr[N])