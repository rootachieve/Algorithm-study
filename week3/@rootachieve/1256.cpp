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

long long map[103][103];

int n, m, k;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= n + 1; i++) {
		map[i][0] = 1;
		map[i][1] = i;
		for (int j = 2; j <= m; j++) {
			if (map[i][j - 1] == -1) {
				map[i][j] = -1;
			}
			else {
				map[i][j] = map[i][j - 1] * (i + j - 1) / j;
				if (map[i][j] > 2000000000) {
					map[i][j] = -1;
				}
			}
		}
	}
	int Ca = n;
	int Cz = m;
	if (map[Ca + 1][Cz] != -1 && map[Ca + 1][Cz] < k) {
		printf("-1");
	}
	else {
		long long Count = 0;
		int index = 0;
		char ans[206];
		while (Ca > 0 || Cz > 0) {
			if (Ca == 0) {
				ans[index++] = 'z';
				Cz--;
			}
			else if (Cz == 0) {
				ans[index++] = 'a';
				Ca--;
			}
			else {
				if (map[Ca][Cz] == -1) {
					ans[index++] = 'a';
					Ca--;
				}
				else {
					if (Count + map[Ca][Cz] >= k) {
						ans[index++] = 'a';
						Ca--;
					}
					else {
						Count += map[Ca][Cz];
						ans[index++] = 'z';
						Cz--;
					}
				}
			}
		}
		ans[index] = NULL;
		printf("%s", ans);
	}
}