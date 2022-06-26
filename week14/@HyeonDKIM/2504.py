# 2504 괄호의 값

import sys
input = sys.stdin.readline

str = input().rstrip()

stack = [] # 스택 사용해서 풀이
error = 1 # 플래그로 반례찾기 ]()같은녀석들 ,,,
#print(str)
#스택에서 가장 높은 녀석들을 꺼내며 [가 오는지 (이 오는지 각각 경우를 생각해서 계산

for i in str:
    #print(i)
    if i == "(":# 기존엔 else로 퉁쳐서 [ ( 추가해줬는데, counter 변수 등장으로 따로 찢어줌
        stack.append(i)
        counter = 0 # 서치 ,,, 해봄 ,,, ())[]와같은 반례: 연속으로 나오는지 확인하는 변수 필요
    elif i == ")":
        a = 0
        while stack:
            tmp = stack.pop()
            if tmp == "(":
                if counter == 0: # 기존에 들어와 있었던 수가 없었다면
                    stack.append(2)
                    counter = 1
                    error = 0
                else:
                    stack.append(a * 2) # 기존에 들어와 있었던 수가 있으면 곱해준다고 했음
                    counter = 1
                    error = 0
                break

            elif tmp == "[": # 다른 괄호 나오면 컷
                print("0")
                exit(0)
            else: # )나 ]가 나오면 더한다고 했다
                a += tmp
                error = 1
        if error == 1:
            print("0")
            exit(0)

    elif i == "[":
        stack.append(i)
        counter = 0

    elif i == "]": # 똑같이 해주기
        a = 0
        while stack:
            tmp = stack.pop()
            if tmp == "[":
                if counter == 0:
                    stack.append(3)
                    counter = 1
                else:
                    stack.append(a * 3)
                    counter = 1
                error = 0
                break

            elif tmp == "(":
                print("0")
                exit(0)
            else:
                a += tmp
                error = 1

        if error == 1:
            print("0")
            exit(0)


ans = 0
#print(stack)
for i in stack:
    if i == "(" or i == "[":
        print("0")
        exit(0)
    else:
        ans += i

print(ans)
