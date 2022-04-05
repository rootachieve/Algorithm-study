#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 2147473647
#define MOD 9901
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int DP[4][100020];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			DP[1][i] = 1;
			DP[2][i] = 1;
			DP[3][i] = 1;
			continue;
		}
		DP[1][i] = MODULAR(DP[3][i - 1],DP[2][i - 1]);
		DP[2][i] = MODULAR(DP[1][i - 1],DP[3][i - 1]);
		DP[3][i] = MODULAR(MODULAR(DP[1][i - 1], DP[2][i - 1]), DP[3][i - 1]);
	}

	printf("%d",MODULAR(MODULAR(DP[1][n], DP[2][n]), DP[3][n]));
}