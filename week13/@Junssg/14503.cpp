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
int r, c, d;
int arr[51][51];
bool check[51][51];
//위 오른쪽 아래 왼쪽
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int DFS(int r, int c, int d, int cnt)
{
	for (int i = 0; i < 4; i++)
	{

		int nd = (d + 3 - i) % 4;
		int nr = r + dr[nd];
		int nc = c + dc[nd];

		if (nr < 0 || nr >= n || nc < 0 || nc >= m || arr[nr][nc] == 1)
			continue;



		if (check[nr][nc] == 0 && arr[nr][nc] == 0)
		{
			check[nr][nc] = 1; //현재 위치 청소
			DFS(nr, nc, nd, cnt + 1);
		}

	}
	int backIdx = d + 2 < 4 ? d + 2 : d - 2;
	int backr = r + dr[backIdx];
	int backc = c + dc[backIdx];
	if (0 <= backr && backr <= n && 0 <= backc && backc <= m)
	{
		if (arr[backr][backc] == 0)
			DFS(backr, backc, d, cnt);

		else
		{
			cout << cnt << endl;
			exit(0);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			check[i][j] = 0;
		}
	}
	check[r][c] = 1;
	DFS(r, c, d, 1);
	return 0;
}


