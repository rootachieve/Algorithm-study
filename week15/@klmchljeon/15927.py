s = input()

alpha = s[0]
mono = True
for i in range(len(s)):
    if s[i] != alpha:
        mono = False

if mono:
    print(-1)
    exit(0)

n = len(s)//2

for i in range(n):
    if s[i] != s[-i-1]:
        print(len(s))
        exit(0)

print(len(s)-1)