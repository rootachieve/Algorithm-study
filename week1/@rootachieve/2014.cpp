#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#define MAX 2147483647
using namespace std;

priority_queue <int, vector<int>,  greater<int>> pq;
int n, k;
short map[120];
int main() {
	scanf("%d%d", &k, &n);
	long long a;

	for (int i = 0; i < k; i++) {
		scanf("%lld", &a);
		map[i] = a;
		pq.push(a);
	}
	sort(map, map + k);
	long long b;
	long long c;
	long long d = map[k-1];
	int Count = 0;
	while (Count < n - 1) {
		b = pq.top();
		pq.pop();
		for (int i = 0; i < k; i++) {
			c = b * map[i];
			if (c > MAX) break;
			pq.push(c);
			if (b % map[i] == 0) break;
		}
		Count++;
	}
	printf("%d", pq.top());
}