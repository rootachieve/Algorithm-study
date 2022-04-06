#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 2147473647
#define MOD 1000000003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int n, m;
int map[5][2002][2002];
int base[2002][2002];
queue <pair<pair<int, int>, int>> q;
int main() {
	scanf("%d%d", &n, &m);
	int a;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a);
			if(a==9){
				q.push(make_pair(make_pair(i, j), 1));
				q.push(make_pair(make_pair(i, j), 2));
				q.push(make_pair(make_pair(i, j), 3));
				q.push(make_pair(make_pair(i, j), 4));
				map[1][i][j] = 1;
				map[2][i][j] = 1;
				map[3][i][j] = 1;
				map[4][i][j] = 1;
			}
			else {
				base[i][j] = a;
			}
		}
	}
	int y, x, ty;
	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		ty = q.front().second;
		q.pop();
		if (base[y][x] == 1) {
			if (ty == 3) {
				if (y + 1 <= n && map[ty][y + 1][x] == 0) {
					map[ty][y + 1][x] = 1;
					q.push(make_pair(make_pair(y + 1, x), ty));
				}
			}
			else if (ty == 1) {
				if (y - 1 >= 1 && map[ty][y - 1][x] == 0) {
					map[ty][y - 1][x] = 1;
					q.push(make_pair(make_pair(y - 1, x), ty));
				}
			}
			else if (ty == 2) {
				if (x - 1 >= 1 && map[4][y][x - 1] == 0) {
					map[4][y][x - 1] = 1;
					q.push(make_pair(make_pair(y, x - 1), 4));
				}
			}
			else {
				if (x + 1 <= m && map[2][y][x + 1] == 0) {
					map[2][y][x + 1] = 1;
					q.push(make_pair(make_pair(y, x + 1), 2));
				}
			}
		}
		else if (base[y][x] == 2) {
			if (ty == 3) {
				if (y - 1 >= 1 && map[1][y - 1][x] == 0) {
					map[1][y - 1][x] = 1;
					q.push(make_pair(make_pair(y - 1, x), 1));
				}
			}
			else if (ty == 1) {
				
				if (y + 1 <= n && map[3][y + 1][x] == 0) {
					map[3][y + 1][x] = 1;
					q.push(make_pair(make_pair(y + 1, x), 3));
				}
			}
			else if (ty == 2) {
				if (x + 1 <= m && map[ty][y][x + 1] == 0) {
					map[ty][y][x + 1] = 1;
					q.push(make_pair(make_pair(y, x + 1), ty));
				}
			}
			else {
				if (x - 1 >= 1 && map[ty][y][x - 1] == 0) {
					map[ty][y][x - 1] = 1;
					q.push(make_pair(make_pair(y, x - 1), ty));
				}
			}
		}
		else if (base[y][x] == 3) {
			if (ty == 3) {
				if (x - 1 >= 1 && map[4][y][x - 1] == 0) {
					map[4][y][x - 1] = 1;
					q.push(make_pair(make_pair(y, x - 1), 4));
				}
			}
			else if (ty == 1) {
				if (x + 1 <= m && map[2][y][x + 1] == 0) {
					map[2][y][x + 1] = 1;
					q.push(make_pair(make_pair(y, x + 1), 2));
				}
			}
			else if (ty == 2) {
				if (y - 1 >= 1 && map[1][y - 1][x] == 0) {
					map[1][y - 1][x] = 1;
					q.push(make_pair(make_pair(y - 1, x), 1));
				}
			}
			else {
				if (y + 1 <= n && map[3][y + 1][x] == 0) {
					map[3][y + 1][x] = 1;
					q.push(make_pair(make_pair(y + 1, x), 3));
				}
			}
		}
		else if (base[y][x] == 4) {
			if (ty == 3) {
				if (x + 1 <= m && map[2][y][x + 1] == 0) {
					map[2][y][x + 1] =  1;
					q.push(make_pair(make_pair(y, x + 1), 2));
				}
			}
			else if (ty == 1) {
				if (x - 1 >= 1 && map[4][y][x - 1] == 0) {
					map[4][y][x - 1] = 1;
					q.push(make_pair(make_pair(y, x - 1), 4));
				}
			}
			else if (ty == 2) {
				if (y + 1 <= n && map[3][y + 1][x] == 0) {
					map[3][y + 1][x] = 1;
					q.push(make_pair(make_pair(y + 1, x), 3));
				}
			}
			else {
				if (y - 1 >= 1 && map[1][y - 1][x] == 0) {
					map[1][y - 1][x] = 1;
					q.push(make_pair(make_pair(y - 1, x), 1));
				}
			}
		}
		else {
			if (ty == 3) {
				if (y + 1 <= n && map[ty][y + 1][x] == 0) {
					map[ty][y + 1][x] = 1;
					q.push(make_pair(make_pair(y + 1, x), ty));
				}
			}
			else if (ty == 1) {
				if (y - 1 >= 1 && map[ty][y - 1][x] == 0) {
					map[ty][y - 1][x] = 1;
					q.push(make_pair(make_pair(y - 1, x), ty));
				}
			}
			else if (ty == 2) {
				if (x + 1 <= m && map[ty][y][x + 1] == 0) {
					map[ty][y][x + 1] = 1;
					q.push(make_pair(make_pair(y, x + 1), ty));
				}
			}
			else {
				if (x - 1 >= 1 && map[ty][y][x - 1] == 0) {
					map[ty][y][x - 1] = 1;
					q.push(make_pair(make_pair(y, x - 1), ty));
				}
			}
		}
	}
	printf("");
	int Count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[1][i][j] != 0 || map[2][i][j] != 0 || map[3][i][j] != 0 || map[4][i][j] != 0) {
				Count++;
			}
		}
	}

	printf("%d", Count);

}