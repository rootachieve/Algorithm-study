# 2212 센서
import sys

input = sys.stdin.readline

N = int(input())
K = int(input())

arr = list(map(int, input().split()))
#print(arr)
arr.sort()

# 집중국 수가 센서 수보다 더 크면 그냥 거기에 설치하면 됨
if K >= N:
    print(0)
    sys.exit()

distance = []
for i in range(1, N):
    distance.append(arr[i] - arr[i-1])

distance.sort(reverse=True)

# 센서간의 거리가 큰 것들부터 빼준다
# 따라서 거리가 짧은 애들만 남음
for _ in range(K-1):
    distance.pop(0)

print(sum(distance))