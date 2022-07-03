#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int count = N;
	int* arr = new int[N];
	int num[5];
	int i, j, k;
	int index = 0;
	while (count--)
	{
		int big = 0;
		for (i = 0; i < 5; i++)
			cin >> num[i];
		for (i = 0; i < 5; i++)
		{
			for (j = i + 1; j < 5; j++)
			{
				for (k = j + 1; k < 5; k++)
				{
					if ((num[i] + num[j] + num[k]) % 10 > big)
					{
						big = (num[i] + num[j] + num[k]) % 10;

					}
				}
			}
		}
		arr[index] = big;
		index++;
	}
	int result;
	int bbig = 0;
	for (i = 0; i < N; i++)
	{
		if (arr[i] >= bbig)
		{
			result = i;
			bbig = arr[i];
		}
	}
	cout << result + 1 << endl;
	delete[] arr;
	return 0;
}