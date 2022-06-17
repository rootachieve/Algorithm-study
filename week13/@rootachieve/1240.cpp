#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<cmath>
#include<cstring>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 2000000001;
#define RESET 0
using namespace std;

vector<pair<int,int>> v[1001];
int n,m;
int depth[1001];
bool visit[1001];
pair<int,int> parent[1001];

void dfs(int node) {
	visit[node] = true;

	for (int i = 0; i < v[node].size(); i++) {
		int t = v[node][i].first;
		int c = v[node][i].second;

		if (!visit[t]) {
			parent[t] = {node,c};
			depth[t] = depth[node] + 1;
			dfs(t);
		}
	}
}
int lca(int a, int b) {
	int sum = 0;
	if (depth[a] > depth[b]) {
		while (depth[a] != depth[b]) {
			sum += parent[a].second;
			a = parent[a].first;
		}
	}
	else {
		while (depth[a] != depth[b]) {
			sum += parent[b].second;
			b = parent[b].first;
		}
	}

	while (a != b) {
		sum+=parent[a].second;
		sum+=parent[b].second;
		a = parent[a].first;
		b = parent[b].first;
	}

	return sum;
}

int main() {
	scanf("%d%d",&n,&m);
	int a,b,c;
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}

	dfs(1);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
}