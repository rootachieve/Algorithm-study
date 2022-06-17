#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int base[10002];
int cal[10002];
int n;
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&base[i]);
	}

	for (int i = 1; i <= n; i++) {
		int Value = 0;
		int Max = base[i];
		int Min = base[i];
		for (int j = i; j >= 1; j--) {
			Max = max(Max,base[j]);
			Min = min(Min,base[j]);
			Value = max(Max-Min+cal[j-1],Value);
		}
		cal[i] = Value;
	}

	printf("%d",cal[n]);
}