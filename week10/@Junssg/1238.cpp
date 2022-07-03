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

int n, m, x;
vector<pair<int, int>> graph[1001];
int dist[1001];
int ans[1001];
void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty())
	{
		int d = -pq.top().first;  //���� �������� ���
		int tmp = pq.top().second;   // ���� ���
		pq.pop();
		if (dist[tmp] < d) //�̹� �ִܰ�θ� üũ���� ���
			continue;
		for (int i = 0; i < graph[tmp].size(); i++)
		{
			int next = graph[tmp][i].first;
			int ncost = graph[tmp][i].second; //���ļ� ���� ����� ��� ���
												 // ��������� ��� + ���� ���
			if (dist[next] > d + ncost)
			{
				dist[next] = d + ncost;
				pq.push({ -dist[next],next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			dist[j] = 987654321;
		dijkstra(i);
		ans[i] = dist[x];
	}
	for (int j = 1; j <= n; j++)
		dist[j] = 987654321;

	dijkstra(x);

	for (int i = 1; i <= n; i++)
		ans[i] = ans[i] + dist[i];

	sort(ans + 1, ans + n + 1);

	cout << ans[n];
	return 0;
}