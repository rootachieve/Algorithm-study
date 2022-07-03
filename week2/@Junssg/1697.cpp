#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int cnt[100001] = { 0, };
queue<int> q;
vector<int> graph[100001];
bool check[100001] = { false, };
int N, K;

void bfs(int start, int ans)
{
	int time = 0;
	q.push(start);
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int tmp = q.front();
			q.pop();
			if (tmp == ans)
			{
				cout << time;
				break;
			}
			if ((tmp > 0) && check[tmp - 1] == 0)
			{

				q.push(tmp - 1);
				check[tmp - 1] = 1;
			}
			if ((tmp < 100000) && check[tmp + 1] == 0)
			{

				q.push(tmp + 1);
				check[tmp + 1] = 1;
			}
			if ((tmp * 2) <= 100000 && check[tmp * 2] == 0)
			{

				q.push(tmp * 2);
				check[tmp * 2] = 1;
			}
		}
		time++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	if (K <= N)
	{
		cout << N - K;
	}
	else
	{
		bfs(N, K);
	}
	return 0;
}