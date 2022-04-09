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
int answer = 0;
int n;
void back(int now) {
	if (now == n) {
		answer++;
	}
	else {
		for (int i = 1; i <= 3; i++) {
			if (i + now <= n) {
				back(now + i);
			}
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		answer = 0;
		back(0);
		printf("%d\n", answer);
	}
}