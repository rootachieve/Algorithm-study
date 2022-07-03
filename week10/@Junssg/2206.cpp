/////////////////////////////////////////////////////
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
int arr[1001][1001];
int check[1001][1001][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int BFS()
{
	queue<pair<pair<int, int>, int>> q;  // x,y,벽뚫횟수
	q.push({ { 0,0 }, 1 });
	check[0][0][1] = 1;
	while (!q.empty())
	{
		int curx = q.front().first.first;
		int cury = q.front().first.second;
		int canbreak = q.front().second;
		q.pop();

		if (curx == n - 1 && cury == m - 1)
			return check[curx][cury][canbreak];
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (arr[nx][ny] == 1 && canbreak) //앞이 벽인데 아직 안뚫었다?
				{
					q.push({ {nx,ny},canbreak - 1 });
					check[nx][ny][canbreak - 1] = check[curx][cury][canbreak] + 1;
				}
				else if (check[nx][ny][canbreak] == 0 && arr[nx][ny] == 0) //벽이미 뚫어서 길로만 가야됨
				{
					q.push({ { nx,ny },canbreak });
					check[nx][ny][canbreak] = check[curx][cury][canbreak] + 1;
				}
			}
		}
		;
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = a[j] - '0';
		}
	}
	cout << BFS();
	return 0;
}


