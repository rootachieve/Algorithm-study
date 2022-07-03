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
int parent[1001] = { 0, };
vector<pair<int, int>> god; //��ǥ�� �ޱ�
vector<tuple<double, int, int>> dist; //

double get_dist(int ax, int ay, int bx, int by)//�� ��ǥ������ �Ÿ�
{
	return sqrt(pow(abs(ax - bx), 2) + pow(abs(ay - by), 2));
}
//int compare(vector<tuple<int, int, double>> a, vector<tuple<int, int, double>> b)
//{
//	int x = get<2> (a);
//	int y = get<2> (b);
//	return x > y;
//}
int find(int u)
{
	if (parent[u] == u)
		return u;
	return parent[u] = find(parent[u]);
}
bool Union(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v)
		return false;
	else
	{
		parent[u] = v;
		return true;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(2);
	cin >> n >> m;
	int a, b;
	double ans = 0;
	god.push_back({ 0,0 }); //0�� ������� �ʱ�����
	for (int i = 1; i <= n; i++) //0�� ������� �ʴ´�
	{
		parent[i] = i;
		cin >> a >> b;
		god.push_back({ a,b });
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		Union(a, b);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			double d = get_dist(god[i].first, god[i].second, god[j].first, god[j].second);
			dist.push_back({ d,i,j });
		}
	}
	sort(dist.begin(), dist.end());
	for (int i = 0; i < dist.size(); i++)
	{
		int u = get<1>(dist[i]);
		int v = get<2>(dist[i]);
		double d = get<0>(dist[i]);
		if (Union(u, v))
		{
			ans += d;
		}
	}
	printf("%.2f", ans);
	return 0;
}
/* prim or kruskal? ..
1. ������ ����ġ�� ���� ������������ ����
2. ���� ���� ���� �̱�
3. ��� ���� �湮�Ҷ����� ���� ������� ���Ѵ� (����Ŭ �ȵǰ�)
*/