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

long long dp[100001] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	dp[0] = 1;

	dp[1] = 3;

	dp[2] = 7;

	dp[3] = 17;

	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 2 * dp[i - 1] + dp[i - 2];
		dp[i] = dp[i] % 9901;
	}
	cout << dp[n];
	return 0;
}