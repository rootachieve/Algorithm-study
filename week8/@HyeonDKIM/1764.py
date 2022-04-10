#1764 듣보잡
import sys

# 무지성은 시간초과

N, M = map(int, input().split())
input = sys.stdin.readline
people = {} # 리스트 시간초과 -> 딕셔너리는?

for i in range(N):
    a = input().rstrip()
    people[a] = a

NotHearSee = []
#print(people)

for i in range(M):
    see = input().rstrip()
    if see in people:
        NotHearSee.append(see)

#사전순으로 출력하세요 ^^ ㅋ 이거때매 ㅈㄴ틀림
NotHearSee.sort()

print(len(NotHearSee))
#print(NotHearSee)
for i in NotHearSee:
    print(i)

#다른 사람은 set로도 풀었음, 더 쉬웠을듯