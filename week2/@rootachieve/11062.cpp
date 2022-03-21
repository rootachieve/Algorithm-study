#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 2147483647
#define MOD 10000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;
int t;
int n;
int DP[1002][1002];
int DPp[1002][1002];
int base[1002];

void back(int s, int e) {
	if (s==e) {
		DP[s][e] = base[s];
		DPp[s][e] = 1;
	}
	else if (s + 1 == e) {
		if (DP[s + 1][e] == 0) {
			back(s + 1, e);
		}

		if (DP[s][e - 1] == 0) {
			back(s, e - 1);
		}

		if(DP[s + 1][e] - base[s] < DP[s][e - 1] - base[e]) {
			DP[s][e] = base[s];
			DPp[s][e] = 1;
		}
		else {
			DP[s][e] = base[e];
			DPp[s][e] = 2;
		}
	}
	else {
		if (DP[s + 1][e] == 0) {
			back(s + 1, e);
		}

		if (DP[s][e - 1] == 0) {
			back(s, e - 1);
		}
		int l, r;
		if (DPp[s + 1][e] == 2) {
			l = DP[s + 1][e - 1] + base[s];
		}
		else {
			l = DP[s + 2][e] + base[s];
		}

		if (DPp[s][e - 1] == 2) {
			r = DP[s][e - 2] + base[e];
		}
		else {
			r = DP[s + 1][e - 1] + base[e];
		}

		if (DP[s + 1][e] - l < DP[s][e - 1] - r) {
			DP[s][e] = l;
			DPp[s][e] = 1;
		}
		else {
			DP[s][e] = r;
			DPp[s][e] = 2;
		}
	}
}
int main() {
	int a;
	int l, r;
	scanf("%d", &t);
	for (int h = 1; h <= t; h++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &base[i]);
			for (int j = i; j <= n; j++) {
				DP[i][j] = 0;
			}
		}
		back(1, n);
		printf("%d\n",DP[1][n]);
	}
}