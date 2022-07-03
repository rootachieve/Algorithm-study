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
int parent[1000001];
int Find(int u)
{
	if (parent[u] == u)
		return u;
	return parent[u] = Find(parent[u]);
}
void Union(int u, int v, int menu)
{
	u = Find(u);
	v = Find(v);

	if (u == v)
	{
		if (menu == 0)
			return;
		else if (menu == 1)
			printf("YES\n");
	}
	else
	{
		if (menu == 0)
			parent[u] = v;
		else if (menu == 1)
			printf("NO\n");
	}


}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++)
	{
		int menu, a, b;
		scanf("%d%d%d", &menu, &a, &b);
		Union(a, b, menu);

	}

	return 0;
}
