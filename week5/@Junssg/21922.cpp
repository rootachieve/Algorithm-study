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
int pos[2001][2001];
bool check[2001][2001];
bool visited[2001][2001][4];
queue<pair<pair<int, int>, int>> q;

int nxt[4][2] = { {-1,0}, {0,1},{1,0} ,{0,-1} }; //»ó¿ìÇÏÁÂ

void BFS()
{
	while (!q.empty())
	{
		int dir = q.front().second;
		int nx = q.front().first.first + nxt[dir][0];
		int ny = q.front().first.second + nxt[dir][1];
		q.pop();
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if (visited[nx][ny][dir])
			continue;
		visited[nx][ny][dir] = 1;
		check[nx][ny] = 1;
		if (pos[nx][ny] == 1 && dir % 2 == 1)
			continue;
		else if (pos[nx][ny] == 2 && dir % 2 == 0)
			continue;
		else if (pos[nx][ny] == 9)
			continue;
		else if (pos[nx][ny] == 3)
		{
			if (dir < 2)
				dir = (dir + 1) % 2;
			else
				dir = 2 + (dir + 1) % 2;
		}
		else if (pos[nx][ny] == 4)
		{
			if (dir == 0)
				dir = 3;
			else if (dir == 3)
				dir = 0;
			else if (dir == 1)
				dir = 2;
			else
				dir = 1;
		}
		q.push({ { nx,ny }, dir });
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt = 0;
	for (int i = 0; i <= 2000; i++)
		for (int j = 0; j <= 2000; j++)
			pos[i][j] = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> pos[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (pos[i][j] == 9)
			{
				cnt++;
				for (int k = 0; k < 4; k++)
				{
					visited[i][j][k] = 1;
					q.push({ {i, j},k });
				}
			}
		}
	}
	BFS();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (check[i][j] == 1)
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;

	return 0;
}