#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 2147483647
#define MOD 10000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

vector<int> v[50020];

int Rank[50020];
int table[17][50020];
bool visit[50020];

void dfs(int node) {
	visit[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		if (!visit[v[node][i]]) {
			Rank[v[node][i]] = Rank[node] + 1;
			table[0][v[node][i]] = node;
			dfs(v[node][i]);
		}
	}
	visit[node] = false;
}
int m,n;
int main() {
	int a, b;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);

	for (int i = 1; i <= 16; i++) {
		for (int j = 1; j <= n; j++) {
			table[i][j] = table[i - 1][table[i-1][j]];
		}
	}

	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		if (Rank[a] < Rank[b]) {
			int c = (Rank[b] - Rank[a]);
			int Count = 0;
			while (c != 0) {
				if ((c & 1) == 1) {
					b = table[Count][b];
				}
				Count++;
				c = c >> 1;
			}
		}
		else if (Rank[b] < Rank[a]) {
			int c = (Rank[a] - Rank[b]);
			int Count = 0;
			while (c != 0) {
				if ((c & 1) == 1) {
					a = table[Count][a];
				}
				Count++;
				c = c >> 1;
			}
		}
		if (a != b) {
			for (int j = 16; j >= 0; j--) {
				if (table[j][a] != table[j][b]) {
					a = table[j][a];
					b = table[j][b];
				}
			}

			while (a != b) {
				a = table[0][a];
				b = table[0][b];
			}
			printf("%d\n", a);
		}
		else {
			printf("%d\n", a);
		}
	}
}