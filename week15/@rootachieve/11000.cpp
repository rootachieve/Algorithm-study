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

int n;

struct Pcompare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};
priority_queue <pair<int,int>,vector<pair<int,int>>, Pcompare> pq;//일찍끝
pair<int, int> sc[200020];//일찍 시작

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}
int main() {
	scanf("%d", &n);
	int s, e;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &s, &e);
		sc[i] = make_pair(s, e);
	}

	sort(sc, sc + n, compare);
	int run = 0;
	int Max = 0;
	for (int i = 0; i < n; i++) {
		while (!pq.empty() && sc[i].first>=pq.top().second) {
			pq.pop();
			run--;
		}

		pq.push(sc[i]);
		run++;
		Max = max(Max, run);
	}

	printf("%d", Max);
}