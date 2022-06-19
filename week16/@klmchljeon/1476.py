#날짜 계산

e,s,m=map(int,input().split())
if e==15:
    e=0
if s==28:
    s=0
if m==19:
    m=0
while True:
    if s%15==e and s%19==m:
        break
    s+=28
if s==0:
    print(7980)
else:
    print(s)