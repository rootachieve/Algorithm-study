# 4803 트리
from collections import deque

# BFS // tree인지 아닌지 판단하는 변수를 하나 두기
# 애들끼리 간선 이은 graph 리스트를 만들기
# 큐에 넣어가며 visited true/false인지 확인
# 큐에서 빠지고 빠지고 빠지고 하다가 visited true인 녀석이 나오면
# 그녀석은 아까전에 지나왔던 녀석이랑 이어진다. 싸이클이다 -> 트리가 아니다

def findtree(x): # x는 각 노드별로 트리인가 아닌가 찾기위한 param, bfs
    q = deque()
    q.append(x)
    isTree = True # tree인지 아닌지 판단
    while q:
        now = q.popleft()
        if visited[now] == True:
            isTree = False
        '''
        이전에 지나왔던 것들과 이어지므로
        tree가 아니게 된다!
        '''

        visited[now] = True
        #print(graph[now])
        for next in graph[now]: # graph[now]에 연결된 녀석들은
            if not visited[next]: # visited가 False라면
                q.append(next) # 다음 q에 집어넣는다

    return isTree

count = 0 # case 카운트용
while True:
    count += 1
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break # 둘다 0이면 종료

    graph = [[] for _ in range(n+1)]
    visited = [False]*(n+1)

    for i in range(m):
        tmp1, tmp2 = map(int, input().split())
        graph[tmp1].append(tmp2)
        graph[tmp2].append(tmp1)

    #print(graph)
    #print(count)

    treecount = 0
    for i in range(1, n+1): # 정점 개수 만큼 체크
        if visited[i] == True:
            continue
        if findtree(i) == True:
            treecount += 1

    #print(treecount)

    if treecount == 1:
        print("Case {}: There is one tree.".format(count))
    elif treecount == 0:
        print("Case {}: No trees.".format(count))
    else:
        print("Case {}: A forest of".format(count), treecount, "trees.")

