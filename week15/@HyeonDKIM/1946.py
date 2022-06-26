# 1946 신입 사원
import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    people = []
    count = 1
    N = int(input())
    for _ in range(N):
        서류, 면접 = map(int, input().split())
        people.append([서류, 면접])

    people.sort() # 우선 서류기준 정렬
    max = people[0][1] # 그 다음 면접 점수 비교

    for i in range(1, N):
        if max > people[i][1]: # 면접 점수 갱신
            count += 1
            max = people[i][1]

    print(count)