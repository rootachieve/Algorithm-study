#통나무 건너뛰기

t = int(input())
for case in range(t):
    n = int(input())
    d = list(map(int,input().split()))

    d.sort()

    result1 = []
    result2 = []

    i = 1
    for num in d:
        result1.append(num) if i==1 else result2.append(num)
        i *= -1
    result2.reverse()

    result = result1 + result2

    dif = abs(result[0]-result[-1])
    for i in range(1,n):
        dif = max(dif, abs(result[i]-result[i-1]))

    print(dif)