n, k = map(int, input().split())
gets = list(map(int, input().split()))
sums = sum(gets)
rest = k - sums
ans = 1
for i in range(rest + 1, rest + n + 1):
    ans = (ans * i) % 1000000007
print(ans % 1000000007)
