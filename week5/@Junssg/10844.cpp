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




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n;
	long long dp[101][10];  //dp[수의 길이][그 자리에 있는 숫자]
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			dp[i][j] = 0;

			if (i == 1 && j != 0)
				dp[i][j] = 1;

		}
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			dp[i][j] = dp[i - 1][j + 1] % 1000000000 + dp[i - 1][j - 1] % 1000000000;
			if (j == 0)
				dp[i][j] = dp[i - 1][1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][8];
		}
	}
	long long sum = 0;

	for (int j = 0; j < 10; j++)
	{
		sum += dp[n][j] % 1000000000;

	}
	cout << sum % 1000000000;

	return 0;
}