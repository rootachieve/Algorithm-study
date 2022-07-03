#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<int> q;
	int N;
	cin >> N;
	int menu;
	while (N--)
	{
		cin >> menu;
		if (menu == 0)
		{
			if (q.empty())
				cout << "0" << "\n";
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
		{
			q.push(menu);
		}
	}
	return 0;
}