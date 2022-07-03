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
pair<int, int> p[200001];
bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n);
	pq.push(p[0].second);
	for (int i = 1; i < n; i++)
	{
		if (pq.top() <= p[i].first)
		{
			pq.pop();
			pq.push(p[i].second);
		}
		else
		{
			pq.push(p[i].second);
		}
	}
	cout << pq.size();
	return 0;
}