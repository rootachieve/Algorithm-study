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

int testcase, n, m;
int s, e;
vector<int> graph[101];
int visited[101] = { 0, };
int BFS(int s, int e)
{
	queue<int> q;
	q.push(s);
	visited[s] = 0;

	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		if (tmp == e)
			return visited[e];
		for (int i = 0; i < graph[tmp].size(); i++)
		{
			int nxt = graph[tmp][i];
			if (visited[nxt] == 0)
			{
				q.push(nxt);
				visited[nxt] = visited[tmp] + 1;
			}
		}
	}



	return -1;

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> s >> e;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	cout << BFS(s, e);
	return 0;
}