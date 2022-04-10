# 1149 RGB 거리

N = eval(input())
RGB = []
for n in range(N):
    RGB.append(list(map(int, input().split())))

# 이전 단계로 넘어가 자신의 색이 아닌 것과 min 비교 후 sum
for i in range(1, N):
    RGB[i][0] = min(RGB[i-1][1], RGB[i-1][2]) + RGB[i][0] # R
    RGB[i][1] = min(RGB[i-1][0], RGB[i-1][2]) + RGB[i][1] # G
    RGB[i][2] = min(RGB[i-1][0], RGB[i-1][1]) + RGB[i][2] # B

#print(RGB[N-1])
ans = min(RGB[N-1])
print(ans)
