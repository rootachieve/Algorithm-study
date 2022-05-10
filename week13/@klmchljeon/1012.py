import sys
input = sys.stdin.readline
t=int(input().strip())


vecx = [1,-1,0,0]
vecy = [0,0,1,-1]

def bfs(p,q):
    field[p][q]=0
    queue = [[p,q]]
    while queue:
        x,y = queue[0][0],queue[0][1]
        del queue[0]
        
        for i in range(4):
            dx = x+vecx[i]
            dy = y+vecy[i]
            
            if 0<=dx<n and 0<=dy<m and field[dx][dy]!=0:
                field[dx][dy]=0
                queue.append([dx,dy])
    return
        

for case in range(t):
    count = 0
    n,m,worm = map(int,input().split())
    field = [[0]*m for i in range(n)]
    for _ in range(worm):
        a,b = map(int,input().split())
        field[a][b]=1
    
    
    for i in range(n):
        for j in range(m):
            if field[i][j]==1:
                bfs(i,j)
                count+=1
    print(count)