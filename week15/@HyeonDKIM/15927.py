# 15927 회문은 회문아니야!!

# 그리디?

S = input()
a = False
aaa = True
for i in range(0, len(S)//2):
    if S[i] is not S[len(S)-i-1]: # 중앙 기준 반대쪽에 있는 애랑 비교
        print(len(S))
        aaa = False
        break

    elif S[i] is not S[i+1]:
        a = True # 연속된문자열인지 여부


if aaa:
    if a:
        print(len(S) - 1)
    else:
        print(-1)
