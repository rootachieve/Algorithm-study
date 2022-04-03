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

int map[102][102];
int check[2][102];
int n;
int m;
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(i!=j){
				map[i][j] = 200;
			}
		}
	}
	int a,b;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d",&a,&b);
		map[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				map[i][j] = min(map[i][j],map[i][k] + map[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i!=j&&map[i][j] < 200) {
		
				check[0][j]++;
				check[1][i]++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n",n - (check[0][i] + check[1][i]) - 1);
	}
}