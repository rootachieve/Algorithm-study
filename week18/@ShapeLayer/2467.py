n = int(input())
gets = list(map(int, input().split()))
l = 0
r = n - 1
ans = [l, r]
prev = gets[l] + gets[r]
while l < r:
    now = gets[l] + gets[r]
    if abs(prev) > abs(now):
        prev = now
        ans = [l, r]
    if now > 0: r -= 1
    elif now < 0: l += 1
    else: break
print(gets[ans[0]], gets[ans[1]])
