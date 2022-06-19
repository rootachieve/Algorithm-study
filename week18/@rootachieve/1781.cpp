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

int n;
int ans;
pair<int,int> base[200020];
int parent[200020];
int Rank[200020];

int find(int x) {
	if (parent[x] == x) return x;
	int y = find(parent[x]);
	parent[x] = y;
	return y;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}
int main() {
	int a, b;
	scanf("%d", &n);

	for (int i = 1; i <= 200000; i++) {
		parent[i] = i;
		Rank[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		base[i] = make_pair(a, b);
	}
	int ans = 0;
	sort(base, base + n, compare);
	for (int i = 0; i < n; i++) {
		if (find(base[i].first) != 0) {
			parent[find(base[i].first)] = find(base[i].first) - 1;
			ans += base[i].second;
		}
	}

	printf("%d", ans);
}