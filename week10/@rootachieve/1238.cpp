#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,s;
vector<pair<int,int>> v[1002];

vector<pair<int, int>> v2[1002];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int D[1002];
int T[1002];
int main() {
	scanf("%d%d%d",&n,&m,&s);
	for (int i = 1; i <= n; i++) {
		D[i]=10000000;
		T[i]=10000000;
	}
	int a,b,c;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back({b,c});
		v2[b].push_back({a,c});
	}
	D[s]=0;
	pq.push({0,s});
	while (!pq.empty()) {
		int node = pq.top().second;
		int t = pq.top().first;
		pq.pop();
		if (t > D[node]) {
			continue;
		}

		for (int i = 0; i < v[node].size(); i++) {
			if (D[v[node][i].first] > t + v[node][i].second) {
				pq.push({t+v[node][i].second,v[node][i].first });
				D[v[node][i].first] = t + v[node][i].second;
			}
		}
	}

	T[s] = 0;
	pq.push({0,s});

	while (!pq.empty()) {
		int node = pq.top().second;
		int t = pq.top().first;
		pq.pop();
		if (t > T[node]) {
			continue;
		}

		for (int i = 0; i < v2[node].size(); i++) {
			if (T[v2[node][i].first] > t + v2[node][i].second) {
				pq.push({ t + v2[node][i].second,v2[node][i].first });
				T[v2[node][i].first] = t + v2[node][i].second;
			}
		}
	}
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		Max = max(Max, D[i]+T[i]);
	}
	printf("%d",Max);

}