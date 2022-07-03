#include <iostream>
using namespace std;

long long tree[1000001];
long long n, m, i;
long long H;
long long sum = 0;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long big = 0;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> tree[i];

		if (tree[i] > big)
			big = tree[i];
	}

	long long low = 0;
	long long high = big;

	while (low <= high)
	{
		sum = 0;
		long long mid = (low + high) / 2;
		H = mid;
		for (i = 0; i < n; i++)
		{
			if (tree[i] >= H)
				sum += tree[i] - H;
		}
		if (sum == m)
		{
			break;
		}
		else if (sum > m)
		{
			low = mid + 1;
		}
		else if (sum < m)
		{
			high = mid - 1;
		}
	}
	if (sum >= m)
		cout << H;
	else if (sum < m)
		cout << H - 1;

	return 0;
}