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

int map[4][55][55];
int base[55][55];
struct info {
	int y;
	int x;
	int dir;
	info(int a, int b, int c) {
		y = a;
		x = b;
		dir = c;
	}
};
int Ey,Ex,Sy,Sx;
char temp[55];
int n;
queue<info> q;
int main() {
	scanf("%d",&n);
	int Count = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%s",&temp);
		for (int j = 1; j <= n; j++) {
			if (temp[j - 1] == '.') {
				base[i][j] = 1;

			}
			else if (temp[j - 1] == '!') {
				base[i][j] = 2;
			}
			else if (temp[j - 1] == '#') {
				if (Count == 1) {
					Sy = i;
					Sx = j;
					base[i][j] = 1;
					Count++;
				}
				else {
					Ey = i;
					Ex = j;
					base[i][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k <= 3; k++) {
				map[k][i][j] = 2500;
			}
		}
	}
	map[0][Sy][Sx] = 1;
	map[1][Sy][Sx] = 1;
	map[2][Sy][Sx] = 1;
	map[3][Sy][Sx] = 1;
	q.push(info(Sy,Sx,1));
	q.push(info(Sy, Sx, 2));
	q.push(info(Sy, Sx, 3));
	q.push(info(Sy, Sx, 0));
	while (!q.empty()) {
		info now = q.front();
		q.pop();
		if (base[now.y][now.x] == 2) {
			if (now.dir == 0) {
				if (base[now.y - 1][now.x] != 0 && map[0][now.y - 1][now.x] > map[0][now.y][now.x]) {
					map[0][now.y - 1][now.x] = map[0][now.y][now.x];
					q.push(info(now.y - 1, now.x, 0));
				}
				if (base[now.y][now.x - 1] != 0 && map[3][now.y][now.x - 1] > map[0][now.y][now.x]) {
					map[3][now.y][now.x - 1] = map[0][now.y][now.x] + 1;
					q.push(info(now.y, now.x - 1, 3));
				}

				if (base[now.y][now.x + 1] != 0 && map[1][now.y][now.x + 1] > map[0][now.y][now.x]) {
					map[1][now.y][now.x + 1] = map[0][now.y][now.x] + 1;
					q.push(info(now.y, now.x + 1, 1));
				}
			}
			else if (now.dir == 1) {
				if (base[now.y][now.x + 1] != 0 && map[1][now.y][now.x + 1] > map[1][now.y][now.x]) {
					map[1][now.y][now.x + 1] = map[1][now.y][now.x];
					q.push(info(now.y, now.x + 1, 1));
				}

				if (base[now.y - 1][now.x] != 0 && map[0][now.y - 1][now.x] > map[1][now.y][now.x]) {
					map[0][now.y - 1][now.x] = map[1][now.y][now.x] + 1;
					q.push(info(now.y - 1, now.x, 0));
				}

				if (base[now.y + 1][now.x] != 0 && map[2][now.y + 1][now.x] > map[1][now.y][now.x]) {
					map[2][now.y + 1][now.x] = map[1][now.y][now.x] + 1;
					q.push(info(now.y + 1, now.x, 2));
				}
			}
			else if (now.dir == 2) {
				if (base[now.y + 1][now.x] != 0 && map[2][now.y + 1][now.x] > map[2][now.y][now.x]) {
					map[2][now.y + 1][now.x] = map[2][now.y][now.x];
					q.push(info(now.y + 1, now.x, 2));
				}
				if (base[now.y][now.x - 1] != 0 && map[3][now.y][now.x - 1] > map[2][now.y][now.x]) {
					map[3][now.y][now.x - 1] = map[2][now.y][now.x] + 1;
					q.push(info(now.y, now.x - 1, 3));
				}
				if (base[now.y][now.x + 1] != 0 && map[1][now.y][now.x + 1] > map[2][now.y][now.x]) {
					map[1][now.y][now.x + 1] = map[2][now.y][now.x] + 1;
					q.push(info(now.y, now.x + 1, 1));
				}
			}
			else {
				if (base[now.y][now.x - 1] != 0 && map[3][now.y][now.x - 1] > map[3][now.y][now.x]) {
					map[3][now.y][now.x - 1] = map[3][now.y][now.x];
					q.push(info(now.y, now.x - 1, 3));
				}

				if (base[now.y - 1][now.x] != 0 && map[0][now.y - 1][now.x] > map[3][now.y][now.x]) {
					map[0][now.y - 1][now.x] = map[3][now.y][now.x] + 1;
					q.push(info(now.y - 1, now.x, 0));
				}
				if (base[now.y + 1][now.x] != 0 && map[2][now.y + 1][now.x] > map[3][now.y][now.x]) {
					map[2][now.y + 1][now.x] = map[3][now.y][now.x] + 1;
					q.push(info(now.y + 1, now.x, 2));
				}
			}
		}
		else {
			if (now.dir == 0) {
				if (base[now.y - 1][now.x] != 0 && map[0][now.y - 1][now.x] > map[0][now.y][now.x]) {
					map[0][now.y - 1][now.x] = map[0][now.y][now.x];
					q.push(info(now.y-1, now.x,0));
				}
			}
			else if (now.dir == 1) {
				if (base[now.y][now.x + 1] != 0 && map[1][now.y][now.x + 1] > map[1][now.y][now.x]) {
					map[1][now.y][now.x + 1] = map[1][now.y][now.x];
					q.push(info(now.y, now.x + 1, 1));
				}
			}
			else if (now.dir == 2) {
				if (base[now.y + 1][now.x] != 0 && map[2][now.y + 1][now.x] > map[2][now.y][now.x]) {
					map[2][now.y + 1][now.x] = map[2][now.y][now.x];
					q.push(info(now.y + 1, now.x, 2));
				}
			}
			else {
				if (base[now.y][now.x - 1] != 0 && map[3][now.y][now.x - 1] > map[3][now.y][now.x]) {
					map[3][now.y][now.x - 1] = map[3][now.y][now.x];
					q.push(info(now.y, now.x - 1, 3));
				}
			}
		}
	}
	int Min = 2501;
	for (int i = 0; i <= 3; i++) {
		if (map[i][Ey][Ex] != 0) {
			Min = min(Min,map[i][Ey][Ex]);
		}
	}
	printf("%d",Min-1);
	
}