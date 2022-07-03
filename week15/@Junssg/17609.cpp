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
int func(string a, int check)
{
	int left, right;
	left = 0;
	right = a.length() - 1;
	while (left < right)
	{
		if (a[left] != a[right])
		{
			if (check == 0)
			{
				int len = right - left;
				if (func(a.substr(left + 1, len), 1) == 0 || func(a.substr(left, len), 1) == 0)
					return 1; //유사회문
				else
					return 2;//유사회문아님
			}
			else
				return 2;

		}
		left++;
		right--;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cout << func(a, 0) << endl;
	}


	return 0;
}