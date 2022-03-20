puts = int(input())
cnt = 0
while puts != 0:
    if puts % 2 == 1:
        cnt += 1
    puts = puts // 2
print(cnt)