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

pair<int, int> point[100001];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		point[i].first = a;
		point[i].second = b;
	}
	sort(point, point + n);
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", point[i].first, point[i].second);

	}
	return 0;
}