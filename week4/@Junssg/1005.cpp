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

int testcase, n, k, w;




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> testcase;
	while (testcase--)
	{
		vector<int> graph[1001];
		queue<int> q;
		int prv[1001] = { 0, };
		int Time[1001] = { 0, };

		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> Time[i];
		for (int i = 1; i <= k; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			prv[b]++;
		}
		cin >> w;
		int ans[1001] = { 0, };
		for (int i = 1; i <= n; i++)
		{
			if (!prv[i])
				q.push(i);
		}
		while (prv[w] > 0)
		{
			int tmp = q.front();
			q.pop();
			for (int next : graph[tmp])
			{
				ans[next] = max(ans[next], ans[tmp] + Time[tmp]);
				if (--prv[next] == 0)
					q.push(next);
			}
		}
		cout << ans[w] + Time[w] << endl;
	}

	return 0;
}