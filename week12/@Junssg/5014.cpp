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
#define INF 987654321
using namespace std;

int n, m, testcase;
int f, s, g, u, d;
bool visited[1000001] = { 0, };
int BFS(int s, int g)
{
	int cnt = 0;
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int tmp = q.front();
			q.pop();
			if (tmp == g)
			{
				return cnt;
			}
			if (tmp + u > 0 && tmp + u <= f && !visited[tmp + u])
			{
				q.push(tmp + u);
				visited[tmp + u] = 1;
			}
			if (tmp - d <= f && tmp - d > 0 && !visited[tmp - d])
			{
				q.push(tmp - d);
				visited[tmp - d] = 1;
			}
		}
		cnt++;

	}








	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> f >> s >> g >> u >> d;
	int res = BFS(s, g);
	if (res == -1)
		cout << "use the stairs";
	else
		cout << res;
	return 0;
}