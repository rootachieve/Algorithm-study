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

int n, m, testcase;
int score[1001];
int dp[1001];
vector <int> graph[50001];
queue<int> q;
int parent[50001];
int depth[50001];
bool check[50001];
int LCA(int u, int v)
{
	//v�� �׻� �� ���� ���� ����
	if (depth[u] > depth[v])
		swap(u, v);

	//v�� u�� ���̱��� ����ø�
	while (depth[u] != depth[v])
		v = parent[v];

	//u�� v�� ������ ������ ����ø�
	while (u != v)
	{
		u = parent[u];
		v = parent[v];
	}
	return u;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	check[1] = true;
	q.push(1);

	while (!q.empty())
	{
		int x = q.front();//�θ���
		q.pop();

		for (int i = 0; i < graph[x].size(); i++)
		{
			if (!check[graph[x][i]])//���� ��� �湮 X ?
			{
				depth[graph[x][i]] = depth[x] + 1;
				check[graph[x][i]] = 1; //�湮 ǥ��
				parent[graph[x][i]] = x; //�θ���� ǥ��
				q.push(graph[x][i]);
			}

		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << endl;
	}
	return 0;
}


