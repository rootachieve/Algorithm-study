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

int i, j;
int n, w, L;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a;
	int Time = 0;
	pair<int, int> t[1001];
	cin >> n >> w >> L;
	for (i = 0; i < n; i++)
	{
		cin >> a;
		t[i].first = a;
		t[i].second = 0;
	}
	int weight = 0;
	int next = 0;
	int now = 0;
	while (t[n - 1].second != w + 1)
	{
		Time++;
		for (i = now; i < next; i++)
			t[i].second++;

		if (t[now].second == w + 1)
		{
			weight -= t[now].first;
			now++;
		}
		if (next < n && weight + t[next].first <= L)
		{
			weight += t[next].first;
			t[next].second++;
			next++;
		}
	}
	cout << Time;
	return 0;
}