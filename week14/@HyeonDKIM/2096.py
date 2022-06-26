# 2096 내려가기

# dp, 점화식

import sys
input = sys.stdin.readline

N = int(input())
aa = list(map(int, input().split())) # 초기값
dp_max = aa
dp_min = aa

# 슬라이딩 윈도우 : 배열 갱신

for _ in range(N-1):
    a, b, c = map(int, input().split())
    # 첫번재는 0,1만, 두번째는 0,1,2로, 3번째는 1,2로 갈수 있음
    dp_max = [a + max(dp_max[0], dp_max[1]), b + max(dp_max), c + max(dp_max[1], dp_max[2])]
    dp_min = [a + min(dp_min[0], dp_min[1]), b + min(dp_min), c + min(dp_min[1], dp_min[2])]

print(max(dp_max), min(dp_min))