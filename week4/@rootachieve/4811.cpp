#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <regex>
#define MAX 2147473647
#define MOD 1000000003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

long long base[32][64];
queue <pair<int, int>> q;
int n;
int main() {
	do {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= 2 * n; j++) {
				base[i][j] = 0;
			}
		}
		q.push(make_pair(n, 0));
		base[n][0] = 1;
		while (!q.empty()) {
			if (q.front().first > 0) {
				if (base[q.front().first - 1][q.front().second + 1] == 0) {
					q.push(make_pair(q.front().first - 1, q.front().second + 1));
				}
				base[q.front().first - 1][q.front().second + 1] += base[q.front().first][q.front().second];
			}

			if (q.front().second > 0) {

				if (base[q.front().first][q.front().second - 1] == 0) {
					q.push(make_pair(q.front().first, q.front().second - 1));
				}
				base[q.front().first][q.front().second - 1] += base[q.front().first][q.front().second];
			}
			q.pop();
		}

		printf("%lld\n", base[0][0]);

	} while (1);
}