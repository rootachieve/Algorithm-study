#include <iostream>
#include <time.h>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, int> p[501];
int d[101];
int N, i, a, b;

int compare(pair<int, int>a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int compare2(pair<int, int>a, pair<int, int> b)
{
	return a.first > b.first;
}

int LIS()
{
	int max = 0;
	for (i = 0; i < N; i++)
	{
		d[i] = 1;
		for (int j = 0; j < N; j++)
		{
			if (p[i].second > p[j].second && d[i] < d[j] + 1)
			{
				d[i] = d[j] + 1;
			}
			if (d[i] > max)
				max = d[i];
		}
	}
	return max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		p[i].first = a;
		p[i].second = b;
	}

	sort(p, p + N, compare);
	cout << N - LIS();
	return 0;
}