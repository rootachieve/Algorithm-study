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

long long fac[23];
long long n;
long long ty;
long long k;
long long base[23];
long long check[23];
int main() {
	scanf("%lld", &n);
	scanf("%lld", &ty);
	fac[1] = 1;
	fac[0] = 1;
	for (long long i = 2; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	if (ty == 1) {
		scanf("%lld", &k);
		long long sum = 0;
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= n; j++) {
				if (check[j] == 0&&k-fac[n-i]<=0) {
					printf("%lld ", j);
					check[j] = 1;
					break;
				}
				else if(check[j]==0){
					k -= fac[n - i];
				}
			}
		}
	}
	else {
		for (long long i = 1; i <= n; i++) {
			scanf("%lld", &base[i]);
		}

		long long sum = 1;
		for (long long i = 1; i <= n; i++) {
			long long Count = 0;
			check[base[i]] = 1;
			for (long long j = 1; j <= n; j++) {
				if (j == base[i]) break;
				if (check[j] == 0) Count++;
			}
			sum += fac[n - i] * Count;
		}
		printf("%lld", sum);
	}
}