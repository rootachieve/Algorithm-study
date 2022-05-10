n = int(input())

depth = [0]*(n+1)
visit = [False]*(n+1)
parent = [0]*(n+1)
graph = [[] for _ in range(n+1)]

for _ in range(n-1):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
    
#bfs(1)
queue = [1]
visit[1] = True
while queue:
    x = queue[0]
    del queue[0]
    
    for i in graph[x]:
        if visit[i] == False:
            parent[i] = x
            visit[i] = True
            depth[i] = depth[x]+1
            queue.append(i)
#

def lca(x,y):
    while depth[x]!=depth[y]:
        if depth[x]>depth[y]:
            x = parent[x]
        else:
            y = parent[y]
    while x != y:
        x = parent[x] 
        y = parent[y]
    return x

m = int(input())
for _ in range(m):
    a,b = map(int,input().split())
    result = lca(a,b)
    print(result)