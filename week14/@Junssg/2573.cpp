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
int arr[301][301];
int tmp[301][301];
bool check[301][301];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void BFS(int r, int c)
{
	queue<pair<int, int>> q;
	q.push({ r,c });
	check[r][c] = true;
	while (!q.empty())
	{
		int curr = q.front().first;
		int curc = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = curr + dx[i];
			int nc = curc + dy[i];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m)
			{
				if (arr[nr][nc] != 0 && check[nr][nc] == 0)
				{
					q.push({ nr,nc });
					check[nr][nc] = true;
				}
			}
		}
	}
}
int ice(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (arr[nx][ny] == 0)
			cnt++;
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			check[i][j] = 0;
		}
	}
	int time = 0;
	while (1)
	{
		int cnt = 0;
		memset(tmp, 0, sizeof(tmp));
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (check[i][j] == 0 && arr[i][j] != 0)
				{
					BFS(i, j);
					cnt++;
				}
			}
		}
		if (cnt == 0)
		{
			cout << '0';
			break;
		}
		else if (cnt >= 2)
		{
			cout << time;
			break;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				tmp[i][j] = arr[i][j] - ice(i, j);
				if (tmp[i][j] < 0)
					tmp[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = tmp[i][j];
			}
		}

		time++;
	}
	return 0;
}





