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

int testcase, n;
long long dp[91];
long long fibo(int x)
{
	if (x <= 2)
		return 1;
	if (dp[x] != 0)
		return dp[x];
	else
	{
		dp[x] = fibo(x - 1) + fibo(x - 2);
		return dp[x];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cout << fibo(n);

	return 0;
}