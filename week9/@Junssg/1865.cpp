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
			graph.push_back({ a, b,c }); //a���� b���� ���µ� c�� �ð��ҿ�
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
/*2. ���� �������� �˰����� if(dist[INF] == continue),
�� ������ �ȵ� ��忡 ���� ����� �����ϴ� �ڵ带 ������ �����ؾ��Ѵ�.
���� �������� �˰����� ���, �� ��忡�� �ٸ� ���� ���� �ִܰŸ��� ���ϱ� ���ϱ� ���ؼ� dist[0] = 1 �� ������ ��带 0���� �ʱ�ȭ �� ���Դϴ�.
������, �� ���������� �׷��� �Ͻø� �ȵ˴ϴ�.�ֳ��ϸ� ��� �׷����� ����Ǿ� �ִٴ� ������ ����, �� 0���� �����ؾ� �Ѵٴ� ���� ���� �����Դϴ�.

���� ���,
1 -> 2 -> 1
3 -> 4 -> 3
2������ �׷����� �ִٰ� �����ϸ�, 3->4->3 �� �׷����� ���� ����Ŭ�� �����Ѵٰ� �ص�, �츮�� 1�� ������ ���縦 �� ���̱� ������, 1�� - 2����� �Ѵ� 3�� - 4�� ���� �� �� �����Ƿ�(dist �� INF�� ���̱� ����), ��������Ŭ�� ���ٰ� �Ǵ�, NO�� ����� ������ �˴ϴ�.
���� �̸� �����ؼ� Ǯ�̸� ���ּž��մϴ�.
*/