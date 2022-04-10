#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<map>
#include <stack>
#define DIV 1000000007
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 1000002;
using namespace std;
long long Count = 0;
long long fac[4000002];
long long base;

long long DC(long long n) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return base;
	}
	else if (n % 2 == 0) {
		long long h = DC(n/2);
		return MODF(h,h);
	}
	else {
		long long h = DC((n-1)/2);
		return MODF(MODF(h,h), base);
	}
}

void calcul(long long n, long long k) {
	if (n > Count) {
		for (long long i = Count + 1; i <= n; i++) {
			fac[i] = MODF(fac[i-1],i);
		}
		Count = n;
	}
	base = MODF(fac[k],fac[n-k]);
	printf("%lld\n",MODF(fac[n],DC(DIV-2)));
}
int main() {
	fac[0] = 1;
	int m;
	int n, k;
	scanf("%d",&m);
	while (m--) {
		scanf("%d%d",&n,&k);
		calcul(n,k);
	}
}