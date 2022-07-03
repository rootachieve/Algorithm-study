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




int parent[501];
int n, m;
bool check[501] = { 0, };
bool isTree[501] = { 0, };
int cycle;
vector<int> graph[501];

int Find(int v);



int Find(int v)
{
	if (v == parent[v])
		return v;
	return Find(parent[v]);
}
void Union(int u, int v, int& setsize)
{
	u = Find(u); //서로 트리를 찾음
	v = Find(v);
	if (u == v || ((!isTree[u]) || (!isTree[v])))//a==b
	{
		isTree[u] = false;
		isTree[v] = false;
	}

	parent[v] = u;
	setsize--;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int casecount = 1;
	while (1)
	{
		cycle = 0;
		cin >> n >> m;
		int setsize = n;
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i <= n; i++)
		{
			isTree[i] = 1;
			parent[i] = i;
		}
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			if (a != b)
			{
				graph[a].push_back(b);
				graph[b].push_back(a);
			}
			else //같으면
				graph[a].push_back(b);
			Union(min(a, b), max(a, b), setsize);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (isTree[Find(i)])
			{
				isTree[Find(i)] = false;
				ans++;
			}
		}
		cout << "Case " << casecount << ": ";
		if (ans <= 0)
			cout << "No trees." << endl;
		else if (ans == 1)
			cout << "There is one tree." << endl;
		else
			cout << "A forest of " << ans << " trees." << endl;
		casecount++;
	}

	return 0;
}