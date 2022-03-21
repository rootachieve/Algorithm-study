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

int n;
int Count[1000020];
int arr[1000020];
bool num[1000020];
int main() {
	scanf("%d", &n);
	int a;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		arr[a] = arr[a - 1] + 1;
		Count[arr[a]]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (Count[i] >= 1) {
			ans += (Count[i] - 1);
		}
	}
	printf("%d", ans);
}