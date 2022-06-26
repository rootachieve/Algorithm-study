# 1476 날짜계산
# 3년 전에 C++로 풀었던 문제

E, S, M = map(int, input().split())

result = 0
year = 1

while True:
    if (year-E) % 15 == 0 and (year-S) % 28 == 0 and (year-M) % 19 == 0:
        result = year
        break
    else:
        year+=1

print(year)