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
stack<int> s;
int arr[1000001] = { 0, };
int ans[1000001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		arr[i] = a;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() && s.top() <= arr[i])
			s.pop();
		if (s.empty())
			ans[i] = -1;
		else
			ans[i] = s.top();

		s.push(arr[i]);

	}
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	return 0;
}
