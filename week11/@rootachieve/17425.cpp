#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#define MAX 100000000001;
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

long long memo[1000001];
int Count = 1;
int n;
int main() {
	for (int i = 1; i <= 1000000; i++)
	{ 
		for (int j = 1; j <= 1000000 / i; j++) { 
			memo[i * j]+=i;
		} 
	}
	for (int i = 1; i <= 1000000; i++) {
		memo[i] = memo[i-1]+memo[i];
	}

	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);

		printf("%lld\n", memo[n]);

	}
}