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

int n, m;
vector<int> v[10001];
int cnt[10001] = { 0, };
bool visited[10001] = { 0, };
queue<int> q;
int big = 0;
void BFS(int start)
{
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < v[tmp].size(); i++)
		{
			if (!visited[v[tmp][i]])
			{
				visited[v[tmp][i]] = true;
				q.push(v[tmp][i]);
			}
		}
		cnt[start]++;
	}
	if (cnt[start] > big)
		big = cnt[start];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		BFS(i);
		memset(visited, false, sizeof(visited)); //다시 방문 초기화
	}
	for (int i = 1; i <= n; i++)
		if (cnt[i] == big)
			cout << i << " ";
	return 0;
}
