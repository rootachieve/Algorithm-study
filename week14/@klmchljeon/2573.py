import sys
input = sys.stdin.readline
n,m = map(int,input().split())
ice = []
for _ in range(n):
    ice.append(list(map(int,input().split())))

visit = [[False]*m for _ in range(n)]
melt = [[0]*m for _ in range(n)]

vecx = [-1,1,0,0]
vecy = [0,0,-1,1]

def bfs(sta,rt):
    queue = [[sta,rt]]
    visit[sta][rt] = True
    
    while queue:
        a,b = queue[0][0], queue[0][1]
        del queue[0]
        
        melt_count = 0
        
        for i in range(4):
            x = a + vecx[i]
            y = b + vecy[i]
            
            #테두리에 0이 둘러져있어서 범위에 벗어나지 않음
            if visit[x][y]==False and ice[x][y] != 0:
                visit[x][y] = True
                queue.append([x,y])
            elif ice[x][y] == 0:
                melt_count += 1
        
        melt[a][b] = melt_count
        
def one_year_later():
    for i in range(n):
        for j in range(m):
            if visit[i][j]:
                ice[i][j] = max(ice[i][j]-melt[i][j],0)
                #초기화
                melt[i][j] = 0
                visit[i][j] = False
                

ice_piece = 0
year = 0
while True:
    for i in range(n):
        for j in range(m):
            if visit[i][j]==False and ice[i][j]!=0:
                bfs(i,j)
                ice_piece += 1
                
    if ice_piece == 1:
        one_year_later()
        ice_piece = 0
        year += 1
    elif ice_piece ==0:
        print(0)
        break
    else:
        print(year)
        break
    