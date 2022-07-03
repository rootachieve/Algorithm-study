#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, i;
	cin >> n >> k;
	int* arr = new int[n];
	int* sum = new int[n] {};
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (i = 1; i <= n - 1; i++)
	{
		arr[i] = arr[i - 1] + arr[i];

	}


	for (i = 1; i < n; i++)
	{
		sum[i] = arr[i] - arr[i - k];
	}
	sum[k - 1] = arr[k - 1];
	int big = sum[k - 1];
	for (i = k - 1; i < n; i++)
	{
		if (sum[i] > big)
			big = sum[i];
	}
	cout << big;

	delete[] arr;
	delete[] sum;
	return 0;
}