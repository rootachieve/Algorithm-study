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
queue<int> q;
int nxt[101] = { 0, };
int mv[101] = { 0, };
void BFS()
{
	q.push(1);
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) //주사위 칸 수 만큼
		{
			int nxtt = tmp + i;
			if (nxtt > 100)
				continue;
			nxtt = nxt[nxtt]; //사다리나 뱀 타고 이동
			if (mv[nxtt] == 0)
			{
				mv[nxtt] = mv[tmp] + 1;
				q.push(nxtt);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= 100; i++)
	{
		nxt[i] = i;
	}
	for (int i = 0; i < n + m; i++)
	{
		int a, b;
		cin >> a >> b;
		nxt[a] = b;
	}
	BFS();
	cout << mv[100];
	return 0;
}
