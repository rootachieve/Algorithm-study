#include <iostream>
#include <algorithm>
using namespace std;

int i;
int dp[301] = { 0, };

int arr[301] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	dp[3] = max(arr[0] + arr[1] + arr[3], arr[0] + arr[2] + arr[3]);
	for (i = 4; i <= N - 1; i++)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << dp[N - 1];
	return 0;
}