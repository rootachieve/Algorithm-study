#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;
int v;
int e;
int w;

int map[3][5500];
int ver[520];
int T;
int coun;

void init() {
	for (int i = 1; i <= v; i++) {
		ver[i] = 200000000;
	}
}
int main() {
	int a, b, c;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d%d", &v, &e, &w);
		init();
		coun = 0;
		for (int j = 1; j <= e; j++) {
			coun++;
			scanf("%d%d%d", &a, &b, &c);
			map[0][coun] = a;
			map[1][coun] = b;
			map[2][coun] = c;
			coun++;
			map[0][coun] = b;
			map[1][coun] = a;
			map[2][coun] = c;
		}
		for (int j = e+1; j <= e+w; j++) {
			coun++;
			scanf("%d%d%d", &a, &b, &c);
			map[0][coun] = a;
			map[1][coun] = b;
			map[2][coun] = -c;
		}


		for (int j = 1; j <= v - 1; j++) {
			for (int k = 1; k <= coun; k++) {
				if (ver[map[1][k]] > ver[map[0][k]] + map[2][k]) {
					ver[map[1][k]] = ver[map[0][k]] + map[2][k];
				}
				
			}
		}


		bool cy = false;
		for ( int g = 1; g <= coun; g++) {
			
			if (ver[map[1][g]] > ver[map[0][g]] + map[2][g]) {
				cy = true;
			}
			
		}

		if (cy) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}