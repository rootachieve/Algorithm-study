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

int Rank[520];
int parent[520];
bool e[520];
int n, m;
int find(int x) {
	if (parent[x] == x) return x;

	int y = find(parent[x]);
	parent[y] = y;
	return y;
}

void merge(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a == b) return;

	if (Rank[a] > Rank[b]) {
		if (e[a] || e[b]) {
			e[a] = true;
			e[b] = false;
		}
		parent[b] = a;
		Rank[a] += Rank[b];
		Rank[b] = 0;
		
	}
	else {
		if (e[a] || e[b]) {
			e[a] = false;
			e[b] = true;
		}
		parent[a] = b;
		Rank[b] += Rank[a];
		Rank[a] = 0;
	}
}
int main() {
	int a, b;
	int c = 0;
	while (1) {
		c++;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			Rank[i] = 1;
			e[i] = false;
		}
		if (n == 0) {
			break;
		}

		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			if (find(a) != find(b)) {
				merge(a, b);
			}
			else {
				e[find(a)] = true;
			}
		}
		int Count = 0;
		for (int i = 1; i <= n; i++) {
			if (Rank[i] > 0 && !e[i]) {
				Count++;
			}
		}

		if (Count == 0) {
			printf("Case %d: No trees.\n", c);
		}
		else if (Count == 1) {
			printf("Case %d: There is one tree.\n", c);
		}
		else {
			printf("Case %d: A forest of %d trees.\n", c, Count);
		}
	}
}