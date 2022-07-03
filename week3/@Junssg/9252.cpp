#include <iostream>
#include <time.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
using namespace std;

int LCS[1001][1001] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	int i, j;
	getline(cin, a);
	getline(cin, b);
	a = "0" + a;
	b = "0" + b;
	int alen = a.size();
	int blen = b.size();

	for (i = 1; i <= blen; i++)
	{
		for (j = 1; j <= alen; j++)
		{
			if (a[j] == b[i])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
			{
				if (LCS[i - 1][j] > LCS[i][j - 1])
					LCS[i][j] = LCS[i - 1][j];
				else
					LCS[i][j] = LCS[i][j - 1];
			}
		}
	}



	string arr;

	int max = 0;
	int maxindex = 0;
	for (i = 0; i < blen; i++)
	{

		for (j = 0; j < alen; j++)
		{

			if (max < LCS[i][j])
			{
				max = LCS[i][j];
				maxindex = j;
			}

		}
	}
	int index = max;
	int j_index = 1001;
	int k = max - 1;
	char ans[1001];
	for (i = blen; i >= 0; i--)
	{
		for (j = alen; j >= 0; j--)
		{
			if ((LCS[i][j] < index) && (j < j_index))
			{
				index = LCS[i][j];
				j_index = j + 1;
				ans[k] = a[j_index];
				k--;
			}
		}


	}
	cout << max;
	if (max != 0)
	{
		cout << endl;
		for (i = 0; i < max; i++)
			cout << ans[i];
	}
	return 0;
}