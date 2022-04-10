# 2805 나무자르기

N, M = map(int, input().split())

arr = list(map(int, input().split()))
first = 0
last = max(arr)

while first <= last:
    sum = 0
    mid = (first+last) // 2
    for i in arr:
        if i >= mid:
            sum = sum + i - mid

    if sum >= M:
        first = mid + 1
    else:
        last = mid - 1

print(last)