#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int parent[10020];
pair<int, int> univ[10020];


int find(int x) {
	if (parent[x] == x) return x;
	int y = find(parent[x]);
	parent[x] = y;
	return y;
}
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first) {
		return true;
	}
	else if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return false;
	}
}
int n;
int a, b;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		univ[i] = make_pair(a, b);
	}
	for (int i = 1; i <= 10000; i++) {
		parent[i] = i;
	}

	sort(univ, univ + n, compare);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int c = find(univ[i].second);
		if (c != 0) {
			ans += univ[i].first;
			parent[c] = c - 1;
		}
	}

	printf("%d", ans);
}