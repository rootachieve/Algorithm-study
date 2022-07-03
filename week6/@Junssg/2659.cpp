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
int arr[4];
int cn[6563] = { 0, };
int make(int arr[])
{
	int num[4];
	num[0] = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
	num[1] = arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[0];
	num[2] = arr[2] * 1000 + arr[3] * 100 + arr[0] * 10 + arr[1];
	num[3] = arr[3] * 1000 + arr[0] * 100 + arr[1] * 10 + arr[2];
	sort(num, num + 4);
	return num[0];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ary[4];
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

	int a = make(arr);
	int idx = 1;
	bool check = 0;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 1; k <= 9; k++)
			{
				for (int p = 1; p <= 9; p++)
				{
					ary[0] = i;
					ary[1] = j;
					ary[2] = k;
					ary[3] = p;

					cn[idx] = make(ary);
					//cout << "현재값은 " << cn[idx] << endl;
					if (cn[idx] == a)
					{
						check = 1;
						break;
					}
					for (int u = 1; u < idx; u++)
					{
						if (cn[idx] == cn[u])
						{
							idx--;
							break;
						}
					}
					idx++;




				}
				if (check == 1)
					break;
			}
			if (check == 1)
				break;
		}
		if (check == 1)
			break;
	}

	cout << idx;
	return 0;
}
