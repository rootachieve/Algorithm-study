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


int m, n; //m이 가로, n이 세로
int tom[1001][1001];
bool visited[1001][1001];
int day[1001][1001];
bool all = 1;
bool check = 1;
queue<pair<int, int>> q;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS()
{
	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (tom[nx][ny] == -1)
				continue;
			if (tom[nx][ny] == 0 && visited[nx][ny] == 0)
			{
				visited[nx][ny] = 1;
				tom[nx][ny] = 1;
				q.push({ nx,ny });
				day[nx][ny] = day[curx][cury] + 1;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int result = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tom[i][j];
			if (tom[i][j] == 0) //처음부터 토마토가 다 익어있는지 체크
				all = 0;
			else if (tom[i][j] == 1)
			{
				visited[i][j] = 1;
				q.push({ i,j });
			}
		}
	}
	if (all == 1) //처음부터 다 익어있는 경우
		cout << "0";
	else
	{
		BFS();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (tom[i][j] == 0)
					check = 0;
				if (day[i][j] >= result)
					result = day[i][j];
			}
		}

		if (check == 0)
			cout << "-1";
		else
			cout << result;
	}
	return 0;
}