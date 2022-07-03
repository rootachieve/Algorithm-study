#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;

	int N, i;
	cin >> N;
	for (i = 1; i < N + 1; i++)
	{
		q.push(i);
	}
	int a;
	while (q.size() > 1)
	{
		q.pop();
		a = q.front();
		q.push(a);
		q.pop();
	}
	cout << q.front();
	return 0;
}