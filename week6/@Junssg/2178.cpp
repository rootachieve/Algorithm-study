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
bool visited[101][101];
int arr[101][101];
queue<pair<int, int>> q;
int ans[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void BFS()
{

	while (!q.empty())// || (q.front().first != n|| q.front().second != m)
	{
		int curx = q.front().first;
		int cury = q.front().second;
		//cout << curx << " " << cury << " ¹æ¹®" << endl;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (visited[nx][ny] == 0 && arr[nx][ny] == 1)
			{
				visited[nx][ny] = 1;
				ans[nx][ny] = ans[curx][cury] + 1;
				q.push({ nx,ny });
			}

		}
	}
}
void init()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			ans[i][j] = 1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	init();
	int size = 0;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		int j = 0;
		size = a.size();
		while (size--)
		{
			arr[i][j] = a[j] - 48;
			j++;
		}

	}


	q.push({ 0, 0 });
	visited[0][0] = 1;

	BFS();

	cout << ans[n - 1][m - 1];
	return 0;
}
