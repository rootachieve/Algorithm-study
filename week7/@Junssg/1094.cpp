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
	int X;
	cin >> X;
	int ans = 0;
	for (int i = 0; i <= 6; i++)
	{
		if (X & (1 << i))
			ans += 1;
	}
	cout << ans;
	return 0;
}
