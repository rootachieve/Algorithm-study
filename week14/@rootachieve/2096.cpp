#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>
#include <unordered_set>
#include <unordered_map>
#define MAX 1002147473647
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;
int Min[2][3];
int Max[2][3];
int n;

int main() {
	scanf("%d",&n);
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a, &b, &c);

		if ((i & 1) == 1) {
			Min[1][0] = min(Min[0][0], Min[0][1]);
			Min[1][1] = min({ Min[0][0],Min[0][1],Min[0][2] });
			Min[1][2] = min(Min[0][1], Min[0][2]);

			Max[1][0] = max(Max[0][0], Max[0][1]);
			Max[1][1] = max({ Max[0][0],Max[0][1],Max[0][2] });
			Max[1][2] = max(Max[0][1], Max[0][2]);

			Min[1][0] += a;
			Min[1][1] += b;
			Min[1][2] += c;

			Max[1][0] += a;
			Max[1][1] += b;
			Max[1][2] += c;

		}
		else {
			Min[0][0] = min(Min[1][0], Min[1][1]);
			Min[0][1] = min({ Min[1][0],Min[1][1],Min[1][2] });
			Min[0][2] = min(Min[1][1], Min[1][2]);

			Max[0][0] = max(Max[1][0], Max[1][1]);
			Max[0][1] = max({ Max[1][0],Max[1][1],Max[1][2] });
			Max[0][2] = max(Max[1][1], Max[1][2]);

			Min[0][0] += a;
			Min[0][1] += b;
			Min[0][2] += c;

			Max[0][0] += a;
			Max[0][1] += b;
			Max[0][2] += c;
		}
	}

	if ((n & 1) == 0) {
		printf("%d ",max({Max[0][0],Max[0][1],Max[0][2]}));
		printf("%d", min({ Min[0][0],Min[0][1],Min[0][2] }));
	}
	else {
		printf("%d ", max({ Max[1][0],Max[1][1],Max[1][2] }));
		printf("%d", min({ Min[1][0],Min[1][1],Min[1][2] }));
	}
}