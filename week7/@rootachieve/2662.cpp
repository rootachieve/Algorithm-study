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

int base[302][22];
int DP[302][22];
int C[302][22];
int n, m;
int main() {
	int a;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a);
			base[i][j] = a;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = i - 1; k >= 0; k--) {
				if (DP[i][j] < DP[k][j - 1] + base[i - k][j]) {
					DP[i][j] = DP[k][j - 1] + base[i - k][j];
					C[i][j] = i - k;
				}
			}
			if (DP[i][j] < DP[i][j - 1]) {
				DP[i][j] = DP[i][j - 1];
				C[i][j] = 0;
			}
		}
	}
	stack<int> s;
	int Count = m;
	int value = n;
	while (Count > 0) {
		if (C[value][Count] == 0) {
			s.push(0);
		}
		else {
			s.push(C[value][Count]);
			value -= C[value][Count];
		}
		Count--;
	}
	printf("%d\n", DP[n][m]);
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
}