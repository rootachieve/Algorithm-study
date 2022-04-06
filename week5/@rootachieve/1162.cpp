#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 1000000003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int n, m, k;
vector<pair<int, long long>> v[210002];
long long D[210002];
int Count;
long long pq[210002];
int loc[210002];

void pop() {
	loc[pq[1]] = 0;
	pq[1] = pq[Count];
	loc[pq[1]] = 1;
	Count--;
	int node = 1;
	bool ch = false;
	do {
		ch = false;

		if (node * 2 + 1 <= Count) {
			if (D[pq[node * 2 + 1]] < D[pq[node * 2]]) {
				if (D[pq[node * 2 + 1]] < D[pq[node]]) {
					int temp = pq[node * 2 + 1];
					pq[node * 2 + 1] = pq[node];
					pq[node] = temp;

					temp = loc[pq[node * 2 + 1]];
					loc[pq[node * 2 + 1]] = loc[pq[node]];
					loc[pq[node]] = temp;

					node = node * 2 + 1;
					ch = true;
				}
			}
			else {
				if (D[pq[node * 2]] < D[pq[node]]) {
					int temp = pq[node * 2];
					pq[node * 2] = pq[node];
					pq[node] = temp;

					temp = loc[pq[node * 2]];
					loc[pq[node * 2]] = loc[pq[node]];
					loc[pq[node]] = temp;

					node = node * 2;
					ch = true;
				}
			}
		}
		else if(node*2<=Count) {
			if (D[pq[node * 2]] < D[pq[node]]) {
				int temp = pq[node * 2];
				pq[node * 2] = pq[node];
				pq[node] = temp;

				temp = loc[pq[node * 2]];
				loc[pq[node * 2]] = loc[pq[node]];
				loc[pq[node]] = temp;

				node = node * 2;
				ch = true;
			}
		}
	} while (ch);
}

void change(int num) {
	int node = loc[num];
	bool ch = false;
	do {
		ch = false;

		if (node != 1) {
			if (D[pq[node / 2]] > D[pq[node]]) {
				int temp = pq[node / 2];
				pq[node / 2] = pq[node];
				pq[node] = temp;

				temp = loc[pq[node / 2]];
				loc[pq[node / 2]] = loc[pq[node]];
				loc[pq[node]] = temp;

				node = node / 2;
				ch = true;
			}
		}
		
	} while (ch);
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	int a, b, c;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &a, &b, &c);
		for (int j = 0; j <= k; j++) {
			v[(a - 1) * (k + 1) + j + 1].push_back(make_pair((b - 1) * (k + 1) + j + 1, c));
			v[(b - 1) * (k + 1) + j + 1].push_back(make_pair((a - 1) * (k + 1) + j + 1, c));
			if (j != k) {
				v[(a - 1) * (k + 1) + j + 1].push_back(make_pair((b - 1) * (k + 1) + j + 2, 0));
				v[(b - 1) * (k + 1) + j + 1].push_back(make_pair((a - 1) * (k + 1) + j + 2, 0));
			}
		}
	}
	for (int i = 1; i <= n * (k + 1); i++) {
		D[i] = (long long)MAX / 2 - 1;
		pq[i] = i;
		loc[i] = i;
	}
	D[1] = 0;
	Count = n*(k+1);
	while (Count > 0) {
		int front = pq[1];
		pop();

		for (int i = 0; i < v[front].size(); i++) {
			if (D[v[front][i].first] > D[front] + v[front][i].second) {
				D[v[front][i].first] = D[front] + v[front][i].second;
				change(v[front][i].first);
			}
		}
	}

	long long Min = (long long)MAX / 2;
	for (int i = (n-1)*(k+1) + 1; i <= n * (k + 1); i++) {
		Min = min(Min, D[i]);
	}

	printf("%lld", Min);
}