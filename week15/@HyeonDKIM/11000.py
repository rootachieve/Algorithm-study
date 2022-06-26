# 11000 강의실 배정

# 우선순위 큐: 몇 주 전에 했었지 큐에 푸쉬하면 정렬되어 쌓임
# 따라서 pop 할 시 끝나는 시간이 가장 빠른 강의부터 나옴
import sys
import heapq

input = sys.stdin.readline
N = int(input())

lecture = [list(map(int, input().split())) for _ in range(N)]

lecture.sort()
q = []
heapq.heappush(q, lecture[0][1])

for i in range(1, N):
    #print(q)
    if lecture[i][0] < q[0]: # 다음 강의시간이 현재 큐의 강의 종료 시각보다 작으면
        #         # 새로운 강의장 개설, 그냥 추가하면 됨
        heapq.heappush(q, lecture[i][1])
    else: # 그렇지 않으면
        # 강의장 추가 필요 X, pop하고 추가함
        heapq.heappop(q) 
        heapq.heappush(q, lecture[i][1])

print(len(q))