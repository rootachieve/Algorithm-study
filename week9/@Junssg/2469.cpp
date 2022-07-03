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

int n, k;
string a;
char up[27];
char down[27];
char arr[1001][27];
char ans[27];
int q;
bool check = true;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//물음표 줄의 위 아래를 비교한다
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		up[i] = 'A' + i;
		cin >> down[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '?') //물음표줄 저장
			{
				q = i;
			}
		}
	}
	for (int i = 0; i < q; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (arr[i][j] == '-') //가로 줄이면 서로 교환
			{
				char tmp = up[j];
				up[j] = up[j + 1];
				up[j + 1] = tmp;
			}
		}
	}
	for (int i = n - 1; i > q; i--)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (arr[i][j] == '-')
			{
				char tmp = down[j];
				down[j] = down[j + 1];
				down[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < k - 1; i++)
	{
		if (up[i] == down[i])
			ans[i] = '*';
		else if (up[i] == down[i + 1] && up[i + 1] == down[i])
		{
			ans[i] = '-';
			char tmp = up[i];
			up[i] = up[i + 1];
			up[i + 1] = tmp;
		}
		else
		{
			check = false;
			break;
		}
	}
	if (check)
	{
		for (int i = 0; i < k - 1; i++)
			cout << ans[i];
	}
	else
	{
		for (int i = 0; i < k - 1; i++)
			cout << "x";
	}
	return 0;
}
