#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
using namespace std;

vector <int> v[100020];
int parent[100020][20];
int depth[100020];
bool visit[100020];
int n, m;
void DFS(int node,int d) {
	for (int i = 0; i < v[node].size(); i++) {
		if (!visit[v[node][i]]) {
			visit[v[node][i]] = true;
			parent[v[node][i]][0] = node;
			depth[v[node][i]] = d + 1;
			DFS(v[node][i],d+1);
		}
	}
}


void make_table() {
	for (int j = 0; j <= 17; j++) {
		for (int i = 1; i <= n; i++) {
			if (parent[i][j] != 0) {
				parent[i][j + 1] = parent[parent[i][j]][j];
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	int a, b;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visit[1] = true;
	depth[1] = 0;
	DFS(1,0);
	make_table();



	scanf("%d", &m);
	int c;

	int k = 1;
	int Count = 0;
	int g, h;
	for (int i = 1; i <= m; i++) {
		Count = 0;
		scanf("%d%d", &a, &b);
		g = a;
		h = b;
		if (depth[g] > depth[h]) {
			c = depth[g] - depth[h];
			while (c >= k) {
				if ((c & k) == 1) {
					g = parent[g][Count];
					
				}
				c = c >> 1;
				Count++;
			}


		}
		else {
			c = depth[h] - depth[g];
			while (c >= k) {
				if ((c & k) == 1) {
					h = parent[h][Count];
				}
				c = c >> 1;
				Count++;
			}
		}
		if (g != h) {
			for (int j = 17; j >= 0; j--) {
				if (parent[g][j] != 0 && parent[g][j] != parent[h][j]) {
					g = parent[g][j];
					h = parent[h][j];
				}
			}
			g = parent[g][0];
		}


		printf("%d\n", g);

	}
}