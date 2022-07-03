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
vector<pair<int, int>> v;
int startx, starty, endx, endy;
int dist;

void BFS()
{
	queue<pair<int, int>> q;
	q.push({ startx,starty });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == endx && y == endy)
		{
			cout << "happy" << endl;
			return;
		}
		for (auto i = v.begin(); i != v.end();)
		{
			int xd = abs(x - i->first);
			int yd = abs(y - i->second);
			if (xd + yd <= 1000)
			{
				q.push({ i->first,i->second });
				i = v.erase(i); //편의점 들렸으니까 삭제
			}
			else
				i++;
		}
	}
	cout << "sad" << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> testcase;
	while (testcase--)
	{
		v.clear();
		cin >> n;
		cin >> startx >> starty;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		cin >> endx >> endy;
		v.push_back({ endx,endy });
		BFS();
	}
	return 0;
}


