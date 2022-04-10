# 1541 잃어버린 괄호

# -가나오면 나머지는 전부 - 처리해주면 된다
# 왜 와이? 괄호로 묵었으니까 ㅋ

string = input()
arr = []
sum = 0

arr = string.split('-')
print(arr)

arr2 = list(map(int, arr[0].split('+')))
print(arr2)
for i in arr2:
    sum = sum + i

# -가 없으면 여기서 코드 끝남 -> +들만 해줌

if len(arr) > 1: # -가 존재할때
    for i in arr[1:]:
        arr3 = list(map(int, i.split('+')))
        print(arr3)
        for j in arr3:
            sum = sum - j


print(sum)