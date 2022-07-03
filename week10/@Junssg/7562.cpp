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

int testcase, n;
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
int visited[301][301];
void Init(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visited[i][j] = 0;
		}
	}
}
void BFS(int startx, int starty, int endx, int endy)
{
	queue<pair<int, int>> q;
	q.push({ startx,starty });
	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		if (curx == endx && cury == endy)
		{
			cout << visited[curx][cury] << endl;
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (!visited[nx][ny])
			{
				q.push({ nx,ny });
				visited[nx][ny] = visited[curx][cury] + 1;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> testcase;
	while (testcase--)
	{
		int startx, starty, endx, endy;
		cin >> n;
		Init(n); //visited ÃÊ±âÈ­
		cin >> startx >> starty;
		cin >> endx >> endy;
		BFS(startx, starty, endx, endy);
	}
	return 0;
}