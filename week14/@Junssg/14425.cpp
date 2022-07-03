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

set<string> s;
string input[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		s.insert(a);
	}
	for (int j = 0; j < m; j++)
	{
		string a;
		cin >> a;
		if (s.count(a) == 1)
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}





