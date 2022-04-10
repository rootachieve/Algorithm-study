# 1388 바닥장식

import sys

input = sys.stdin.readline

N, M = map(int, input().split())

arr = []
for i in range(N):
    arr.append(list(input()))

def checker():
    tmp = 0
    # 가로 탐색
    for i in range(N):
        tmps = ''
        for j in range(M):
            if arr[i][j] == '-':
                if arr[i][j] != tmps: # 벽, |면 막대 하나 추가
                    tmp +=1
            tmps = arr[i][j]

    # 세로 탐색
    for j in range(M):
        tmps = ''
        for i in range(N):
            if arr[i][j] == '|':
                if arr[i][j] != tmps: # 벽, -면 막대 하나 추가
                    tmp += 1
            tmps = arr[i][j]

    return tmp

print(checker())
