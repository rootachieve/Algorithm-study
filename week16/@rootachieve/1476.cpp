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
int e, s, m;
int a, b, c;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	e = 1;
	s = 1;
	m = 1;
	int i;
	for (i = 1;; i++) {
		if (e == a && b == s && c == m) {
			break;
		}
		s++;
		e++;
		m++;
		if (s > 28) {
			s = 1;
		}

		if (m > 19) {
			m = 1;
		}

		if (e > 15) {
			e = 1;
		}
	}

	printf("%d", i);
}