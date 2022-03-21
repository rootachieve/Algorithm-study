#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>
#define MAX 2147483647
#define MOD 10000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

long long DP[10003][102];

long long cost[102];
long long value[102];
long long k;
long long n;
long long costSum;
int main() {
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &value[i]);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &cost[i]);
		costSum += cost[i];
	}
	for (int i = 1; i <= costSum; i++) {
		for (int j = 0; j <= n; j++) {
			if (i >= cost[j]) {
				if (i == 0) {
					DP[i][j] = max(0LL, DP[i - cost[j]][j] + value[j]);
				}
				else {
					DP[i][j] = max(DP[i][j-1], DP[i - cost[j]][j-1] + value[j]);
				}
			}
			else {
				DP[i][j] = DP[i][j - 1];
			}
		}
	}
	printf("");

	for (int i = 0; i <= costSum; i++) {
		if (DP[i][n] >= k) {
			printf("%d", i);
			break;
		}
	}
}