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

string a;
int func()
{
	int len = a.length();
	for (int i = 0; i < len / 2; i++)
	{
		if (a[i] != a[len - i - 1])
		{
			return len;
		}
	}
	for (int i = 1; i < len; i++)
	{
		if (a[0] != a[i])
			return len - 1;
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> a;

	cout << func();

	return 0;
}