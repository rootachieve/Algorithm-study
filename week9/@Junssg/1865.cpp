#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
using namespace std;

int tc, n, m, w;

vector<tuple<int, int, int>> graph;
int dist[501];
void bf(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int tmp = 0; tmp < graph.size(); tmp++)
		{
			int from = get<0>(graph[tmp]);
			int to = get<1>(graph[tmp]);
			int cost = get<2>(graph[tmp]);
			if (dist[from] + cost < dist[to])
				dist[to] = dist[from] + cost;
		}
	}
	for (int tmp = 0; tmp < graph.size(); tmp++)
	{
		int from = get<0>(graph[tmp]);
		int to = get<1>(graph[tmp]);
		int cost = get<2>(graph[tmp]);
		if (dist[from] + cost < dist[to])
		{
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	while (tc--)
	{
		bool visited[501] = { 0, };
		int time = 0;
		queue<int> q;
		cin >> n >> m >> w;
		graph.clear();
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			graph.push_back({ a, b,c }); //a에서 b까지 가는데 c의 시간소요
			graph.push_back({ b, a,c });
		}
		for (int i = 0; i < w; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			c = -1 * c;
			graph.push_back({ a, b,c });
		}
		bf(n);
	}
	return 0;
}
/*2. 기존 벨만포드 알고리즘의 if(dist[INF] == continue),
즉 갱신이 안된 노드에 대한 계산을 배제하는 코드를 오히려 제거해야한다.
보통 벨만포드 알고리즘의 경우, 한 노드에서 다른 노드로 가는 최단거리를 구하기 위하기 위해서 dist[0] = 1 등 임의의 노드를 0으로 초기화 할 것입니다.
하지만, 이 문제에서는 그렇게 하시면 안됩니다.왜냐하면 모든 그래프가 연결되어 있다는 조건이 없고, 꼭 0에서 시작해야 한다는 말이 없기 때문입니다.

예를 들어,
1 -> 2 -> 1
3 -> 4 -> 3
2가지의 그래프가 있다고 생각하면, 3->4->3 의 그래프가 음수 사이클이 존재한다고 해도, 우리는 1의 노드부터 조사를 할 것이기 때문에, 1번 - 2번노드 둘다 3번 - 4번 노드로 갈 수 없으므로(dist 가 INF일 것이기 때문), 음수사이클이 없다고 판단, NO를 출력해 버리게 됩니다.
따라서 이를 주의해서 풀이를 해주셔야합니다.
*/