#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <string>
#include <unordered_set>
#include <unordered_map>
#define MAX 1002147473647
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

int n,m;
vector<int> v[100001];
int lazy[100001];
void dfs(int node) {
	for (int i = 0; i < v[node].size(); i++) {
		lazy[v[node][i]]+=lazy[node];
		dfs(v[node][i]);
	}
}

int main() {
	int a,b;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&a);
		if (i != 1) {
			v[a].push_back(i);
		}
	}

	for (int i = 1; i <= m; i++) {
		scanf("%d%d",&a,&b);
		lazy[a]+=b;
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		printf("%d ",lazy[i]);
	}
}