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
int Count[6];
int map[17][17];
int visit[17][17];
int Min = 101;
void back(int Y, int X,int Cnt) {
	int x = X;
	int y = Y;

	if (Cnt > Min) return;

	while (1) {
		x++;

		if (x > 10) {
			x = 1;
			y++;
		}

		if (y > 10) {
			break;
		}

		if (map[y][x] == 1&&visit[y][x]==0) {
			for (int i = 1; i <= 5; i++) {
				if (Count[i] < 5 && x + i - 1 <= 10 && y + i - 1 <= 10) {
					bool err = false;
					for (int j = 0; j < i; j++) {
						if (err) {
							break;
						}
						for (int k = 0; k < i; k++) {
							if (visit[y + j][x + k] == 1 || map[y + j][x + k] == 0) {
								err = true;
								break;
							}
						}
					}

					if (!err) {
						for (int j = 0; j < i; j++) {
							for (int k = 0; k < i; k++) {
								visit[y + j][x + k] = 1;
							}
						}
						Count[i]++;
						back(y, x,Cnt+1);
						Count[i]--;
						for (int j = 0; j < i; j++) {
							for (int k = 0; k < i; k++) {
								visit[y + j][x + k] = 0;
							}
						}

					}
				}
			}
			return;
		}

		
	}
	Min = min(Cnt, Min);
}

int main() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	back(1, 0, 0);
	if (Min == 101) {
		printf("-1");
	}
	else {
		printf("%d", Min);
	}
}