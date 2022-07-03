#include <iostream>
using namespace std;


int arr[129][129];

int white = 0;
int blue = 0;

void divide(int n, int xstart, int ystart) //�ʱⰪ start 0 end 7
{
	int check = 0;

	for (int i = xstart; i < xstart + n; i++)
	{
		for (int j = ystart; j < ystart + n; j++)
		{
			int index = arr[xstart][ystart];
			if (arr[i][j] != index)
			{
				check = 1;
				break;
			}
		}
		if (check == 1)
			break;
	}
	if (check == 0)
	{
		if (arr[xstart][ystart] == 1)
			blue++;
		else if (arr[xstart][ystart] == 0)
			white++;
	}
	else
	{
		divide(n / 2, xstart, ystart);
		divide(n / 2, xstart + n / 2, ystart);
		divide(n / 2, xstart, ystart + n / 2);
		divide(n / 2, xstart + n / 2, ystart + n / 2);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	divide(n, 0, 0);
	cout << white << '\n';
	cout << blue << '\n';
	return 0;
}