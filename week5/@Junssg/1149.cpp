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

int dp[1001][3];
int color[1001][3];
int indexx[1001] = { 0, };
int small = 999999999;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			color[i][j] = 0;
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> color[i][j];
			dp[i][j] = color[i][j];
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int left = 0;
			int right = 0;
			if (j == 0)
			{
				left = 1;
				right = 2;
			}
			else if (j == 1)
			{
				left = 0;
				right = 2;
			}
			else
			{
				left = 0;
				right = 1;
			}
			dp[i][j] = min(dp[i][j] + dp[i - 1][left], dp[i][j] + dp[i - 1][right]);
		}
	}

	for (int j = 0; j < 3; j++)
	{
		if (dp[n - 1][j] < small)
			small = dp[n - 1][j];
	}
	cout << small;


	return 0;
}