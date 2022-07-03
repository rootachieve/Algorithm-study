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
int score[1001];
int dp[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}
	for (int i = 0; i < n; i++)
	{
		int max_ = score[i];
		int min_ = score[i];
		for (int j = i; j >= 0; j--)
		{
			max_ = max(max_, score[j]);
			min_ = min(min_, score[j]);
			dp[i + 1] = max(dp[i + 1], dp[j] + max_ - min_);
		}
	}
	cout << dp[n];

	return 0;
}


