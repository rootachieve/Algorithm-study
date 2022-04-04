#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

pair<int, int> con[520];

int map[520];

int D[520];
int n;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	int a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a,&b);
		con[i - 1] = make_pair(a, b);
	}

	sort(con, con + n, compare);

	printf("");

	for (int i = 0; i < n; i++) {
		map[i] = con[i].second;
	}


	int Count = 1;
	for (int i = 0; i < n; i++) {
		int index = lower_bound(D, D + Count, map[i]) - D;
		if (index == Count) {
			D[Count] = map[i];
			Count++;
		}
		else {
			if (D[index] > map[i]) {
				D[index] = map[i];
			}
		}
	}

	printf("%d",n - (Count-1));
	
}