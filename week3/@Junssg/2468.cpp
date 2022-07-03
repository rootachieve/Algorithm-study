#include <iostream>
#include <time.h>
#include <algorithm>
#include <utility>
using namespace std;

int N;
int cnt = 0;
bool check[101][101] = { 0, };
bool visited[101][101] = { 0, };

void DFS(int x, int y)
{
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		if (y < N - 1 && visited[x][y + 1] == 0 && check[x][y + 1] == 0)//아래로 이동
			DFS(x, y + 1);
		if (y > 0 && visited[x][y - 1] == 0 && check[x][y - 1] == 0)//위로 이동
			DFS(x, y - 1);
		if (x < N - 1 && visited[x + 1][y] == 0 && check[x + 1][y] == 0)//오른쪽
			DFS(x + 1, y);
		if (x > 0 && visited[x - 1][y] == 0 && check[x - 1][y] == 0)
			DFS(x - 1, y);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int i, j;
	cin >> N;
	int arr[101][101];

	int highest = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > highest)
				highest = arr[i][j];
		}
	}
	int big = 0;
	for (int water = 0; water <= highest; water++)
	{
		cnt = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				check[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (arr[i][j] <= water)
				{
					check[i][j] = 1;
				}
			}
		}
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (check[i][j] == 0 && visited[i][j] == 0)
				{
					DFS(i, j);
					cnt++;
				}
			}
		}
		if (cnt > big)
		{
			big = cnt;
		}
	}
	cout << big;
	return 0;
}