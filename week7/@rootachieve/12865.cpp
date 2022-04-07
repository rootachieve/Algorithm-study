#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;

int dp[110][1000020];
int n, m;
int tem[3][110];


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &tem[1][i], &tem[2][i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j - tem[1][i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - tem[1][i]] + tem[2][i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	printf("%d", dp[n][m]);
}