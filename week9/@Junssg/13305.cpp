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

int n;
long long road[100001] = { 0, };
long long gas[100001] = { 0, };
long long dp[100001] = { 0, };
long long small = 1000000000;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	scanf("%d", &n);
	long long sum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%lld", &road[i]);

	}

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &gas[i]);
	}
	int min = gas[0];
	sum = road[0] * gas[0];
	small = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (gas[i] <= min)
		{
			min = gas[i];
			small = i;
		}
		sum += gas[small] * road[i];
	}
	printf("%lld", sum);
	return 0;
}
