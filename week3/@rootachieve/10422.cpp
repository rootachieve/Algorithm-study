#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 2147473647
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

long long base[5020];

long long fac[5020];

long long back(long long b, long long v) {
	if (b == 0) {
		return 1;
	}
	else if (b == 1) {
		return v;
	}
	else if (b % 2 == 0) {
		long long even = back(b / 2,v);
		return MODULARF(even, even);
	}
	else {
		long long even = back(b - 1, v);
		return MODULARF(even, v);
	}
}
long long combi(long long n) {
	return MODULARF(fac[2*n], back(MOD - 2, MODULARF(fac[n], fac[n + 1])));
}
int t, n;
int main() {
	fac[0] = 1;
	for (int i = 1; i <= 5000; i++) {
		fac[i] = MODULARF(fac[i - 1], i);
	}
	scanf("%d", &t);
	for (int h = 1; h <= t; h++) {
		scanf("%d", &n);
		if (n % 2 == 1) {
			printf("0\n");
		}
		else {
			printf("%lld\n", combi(n / 2)%MOD);
		}
	}
}