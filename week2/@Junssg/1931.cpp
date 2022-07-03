#include <iostream>
#include <time.h>
#include <algorithm>
#include <utility>
using namespace std;


bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	/*clock_t START, END;
	START = clock();
	double result;*/
	///////////
	int n;
	cin >> n;
	pair<int, int> p[100001];
	int last = -1;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + n, compare);

	for (int i = 0; i < n; i++)
	{
		if (p[i].first >= last)
		{
			last = p[i].second;
			count++;
		}
	}
	cout << count;
	//////////////
	/*END = clock();
	result = (double)(END- START)/CLOCKS_PER_SEC;
	cout << "실행시간은 " << result;*/
	return 0;
}