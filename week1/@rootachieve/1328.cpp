#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define IMAX 2147483647
#define MOD 1000000007

#define MODULAPLUS(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULAFLEX(x,y) (((x)%MOD)*((y)%MOD))%MOD
using namespace std;
long long DP[102][102][101];
int n, l, r;
int main() {
	scanf("%d%d%d", &n, &l, &r);
	DP[1][1][n] = 1;
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				if (j < l) {
					DP[j + 1][k][i - 1] = MODULAPLUS(DP[j + 1][k][i - 1], DP[j][k][i]);
				}

				if (k < r) {
					DP[j][k + 1][i - 1] = MODULAPLUS(DP[j][k + 1][i - 1], DP[j][k][i]);
				}

				if(i >= 2) {
					DP[j][k][i - 1] = MODULAPLUS(DP[j][k][i - 1], MODULAFLEX(DP[j][k][i], n - i));
				}

			}
		}
	}

	printf("%lld", DP[l][r][1] % MOD);
}

