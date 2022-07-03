#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int N, i, k;
	cin >> N >> k;
	int* answer = new int[N];
	//SimpleQueue q(N);
	for (i = 1; i < N + 1; i++)
	{
		q.push(i);
	}
	int index = 0;
	int a;
	while (!q.empty())
	{
		for (i = 0; i < k - 1; i++)
		{
			a = q.front();
			q.pop();
			q.push(a);
		}
		answer[index] = q.front();
		q.pop();
		index++;
	}
	cout << "<";

	for (i = 0; i < N; i++)
	{
		if (i == N - 1)
			cout << answer[i];
		else
			cout << answer[i] << ", ";
	}
	cout << ">";
	delete[] answer;
	return 0;
}