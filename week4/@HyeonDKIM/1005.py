# 1005 ACM Craft

from collections import deque
T = int(input())

for _ in range(T):
    N, K = map(int, input().split()) # 건물 수, 규칙 개수
    D = [0] + list(map(int, input().split())) # 시간
    graph = [[] for _ in range(N + 1)] # 위상정렬그래프
    indegree = [0] * (N + 1) # 진입차수

    # 그래프 그리기
    for i in range(K):
        tmp1, tmp2 = map(int, input().split())
        # tmp1 -> 이동 전 정점, tmp2 -> 이동 후 정점
        graph[tmp1].append(tmp2)
        indegree[tmp2] = indegree[tmp2] + 1 # 차수 증가

    dp = [0] * (N + 1)
    q = deque()

    for i in range(1, N + 1):
        if indegree[i] == 0: # 진입차수 0인 것 큐에 삽입
            q.append(i)
            dp[i] = D[i] # 건설시간 dp에 넣어주기

    while q:
        now = q.popleft()

        for i in graph[now]: # 연결된 노드들 진입차수 1 빼기
            indegree[i] = indegree[i] - 1
            dp[i] = max(dp[now] + D[i], dp[i]) # 건물건설시간 큰것 선택
            # A B가 같은 차수이고 100, 10의 시간이라면 100의 시간이 흘러야
            # A B가 모두 건설된 것으로 간주하기 때문일 것이다~
            if indegree[i] == 0: # 다시 진입차수 0 되는 노드 큐에 삽입
                q.append(i)

    last = int(input())
    print(dp[last])