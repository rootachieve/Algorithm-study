from sys import stdin
from sys import stdout
n = int(stdin.readline())
puts = []
grps = {}

def chk_grps(x, y, grps):
    i = 0
    near = []
    for i in grps:
        if [x-1, y] in grps[i] or [x+1, y] in grps[i] or [x, y+1] in grps[i] or [x, y-1] in grps[i]:
            near += [i]
    if not near:
        grps[i+1] = [[x, y]]
        return grps
    elif len(near) == 1:
        grps[near[0]] += [[x, y]]
        return grps
    else:
        grp = []
        init = near[0]
        for n in range(len(near)):
            if n == 0:
                continue
            grps[init] += grps.pop(near[n]-(n-1))
        grps[init] += [[x, y]]
        return grps

for _ in range(n):
    puts += [list(stdin.readline().rstrip())]
for a in range(len(puts)):
    for b in range(len(puts[a])):
        if puts[a][b] == '1':
            grps = chk_grps(b, a, grps)

print(len(grps))
arr = []
for i in grps:
    arr += [len(grps[i])]
arr.sort()
for len_ in arr:
    print(len_)