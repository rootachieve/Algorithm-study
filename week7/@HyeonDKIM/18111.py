# 18111 마인크래프트
import sys # 시간초과 주의

# 주어진 시간 1초? 무조건 pypy

N, M, B = map(int, sys.stdin.readline().split())
land = []
time , h = 100000000, 0

for i in range(N):
    tmp = list(map(int, sys.stdin.readline().split()))
    land.append(tmp)

#print(land)

# 땅 높이 낮으면 블록 꺼내 현재 높이 ++
# 땅 높이 높으면 가장 위 블록 인벤으로 (땅 밀기)

for height in range(257): # height -> 현재 탐색하는 높이
    bottom = top = 0

    # 두 가지 방법
    for i in range(N):
        for j in range(M):
            if land[i][j] < height:
                bottom += height - land[i][j] # 다시 쌓기
            else:
                top += land[i][j] - height # 땅 밀기

    if bottom > top + B: # 가진 블록으로는 채울 수 없다 continue
        continue
    t = bottom + top * 2
    if t <= time: # 다시 돌아가기 위해 값 초기화
        time = t # time이 기존 시간보다 적게 걸리면 얘를 적용
        h = height # 마찬가지로 height 적용

print(time, h)