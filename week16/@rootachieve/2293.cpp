#include <iostream>
#include <stdio.h>
#include <algorithm>


using namespace std;
int map[2][10001];
int n, k;

int main() {
	int a;
	scanf("%d%d", &n, &k);
	int i;
	int j;

	map[0][0] = 1;
	map[1][0] = 1;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		if (i % 2 == 0) {
			for (j = 1; j <= k; j++) {
				if (a > j) {
					map[0][j] = map[1][j];
				}
				else {
					map[0][j] = map[0][j - a] + map[1][j];
				}
			}
		}
		else {
			for (j = 1; j <= k; j++) {
				if (a > j) {
					map[1][j] = map[0][j];
				}
				else {
					map[1][j] = map[1][j - a] + map[0][j];
				}
			}
		}
	}

	if (n % 2 == 0) {
		printf("%d", map[0][k]);
	}
	else {
		printf("%d", map[1][k]);
	}
}