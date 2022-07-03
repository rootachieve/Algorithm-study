#include <iostream>
#include <vector>
using namespace std;

int N;
int count = 0;
int heap[100001] = { 0, };
int index = 1;
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void push(int x)
{
	heap[index] = x;

	int tmp = x;
	int i = index;
	int parent = heap[i / 2];


	while (i != 1 && x > parent)
	{
		int tmp2 = heap[i / 2];
		heap[i / 2] = x;
		heap[i] = tmp2;
		i = i / 2;
		parent = heap[i / 2];
		x = tmp;
	}
	index++;

}
int left(int a)
{
	return heap[a * 2];
}
int right(int a)
{
	return heap[a * 2 + 1];
}
void erase()
{
	int parent = 1;
	int child = 2;
	int root = heap[1];
	int last = heap[index];
	while (child <= index)
	{
		if (child < index && left(parent) < right(parent))
			child += 1;
		if (last >= heap[child])
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = last;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int test = N;

	int k;
	while (test--)
	{
		cin >> k;

		if (k == 0)
		{
			if (heap[1] == 0)
			{
				cout << "0" << '\n';
			}
			else
			{
				/*cout << "Ãâ¹ß" << endl;
				for (int a = 0; a < N; a++)
					cout << heap[a] << endl;*/
				cout << heap[1] << '\n';
				erase();

			}
		}
		else
		{
			push(k);
		}
	}
	return 0;
}