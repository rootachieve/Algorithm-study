#A->B

start,goal = input().split()

def convert(n,i):
    if i==1:
        return str(int(n)*2)
    
    else:
        return n+'1'

queue = [[start,1]]

while queue:
    x,n = queue[0][0], queue[0][1]
    del queue[0]
    

    if x==goal:
        print(n)
        exit(0)
    
    for i in range(2):
        s = convert(x,i)
        if len(s)<=len(goal):
            queue.append([s,n+1])
    
print(-1)