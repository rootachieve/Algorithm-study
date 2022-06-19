#에라토스테네스의 체
sieve = [False]*2 + [True]*(9999)
for i in range(2,10000):
    if sieve[i]:
        for j in range(i+i,10000,i):
            sieve[j] = False

prime = {}
index = 0
for i in range(1000,10000):
    if sieve[i]:
        prime[str(i)] = index
        index+=1

def bfs(a):
    queue = [[a,0]]
    while queue:
        x = queue[0]
        del queue[0]

        if x[0] == c:
            print(x[1])
            return

        for i in range(4):
            for j in range(10):
                n = x[0][:i]+str(j)+x[0][i+1:]
                if n in prime and not visit[prime[n]]:
                    visit[prime[n]] = True
                    queue.append([n,x[1]+1])

    print('Impossible')
    return

t = int(input())
for case in range(t):
    p,c = input().split()

    visit = [False]*len(prime)
    
    bfs(p)