#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int n,s,e,m;
long long D[155];
long long Pro[155];
bool visit[155];
vector<int> v[155];

typedef struct ed{
	int s;
	int e;
	long long cost;
	ed(int a, int b, long long c) {
		s = a;
		e = b;
		cost = c;
	}
}ed;
vector<ed> edge;
int main() {
	scanf("%d%d%d%d",&n,&s,&e,&m);
	int a,b;
	long long c;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld",&a,&b,&c);
		v[a].push_back(b);
		edge.push_back(ed(a,b,c));
	}

	for (int i = 0; i < n; i++) {
		D[i] = 0x3f3f3f3f3f3f3f3f;
		scanf("%lld",&Pro[i]);
	}
	D[s] = -Pro[s];
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j < edge.size(); j++) {
			if (D[edge[j].s]!= 0x3f3f3f3f3f3f3f3f &&D[edge[j].s] + (edge[j].cost - Pro[edge[j].e]) < D[edge[j].e]) {
				D[edge[j].e] = D[edge[j].s] + (edge[j].cost - Pro[edge[j].e]);
			}
		}
	}
	queue<int>target;
	int memo = D[e];
	bool cy = false;
	for (int j = 0; j < edge.size(); j++) {
		if (D[edge[j].s] != 0x3f3f3f3f3f3f3f3f && D[edge[j].s] + (edge[j].cost - Pro[edge[j].e]) < D[edge[j].e]) {
			D[edge[j].e] = D[edge[j].s] + (edge[j].cost - Pro[edge[j].e]);
	
			target.push(edge[j].s);
			visit[edge[j].s] = true;
			cy = true;	
		}
	}
	if (D[e] == 0x3f3f3f3f3f3f3f3f) {
		printf("gg");
	}
	else {
		if (cy) {
			
			while (!target.empty()) {
				int node = target.front();
				target.pop();
				for (int i = 0; i < v[node].size(); i++) {
					if(!visit[v[node][i]]){
						visit[v[node][i]] = true;
						target.push(v[node][i]);
					}
				}
			}

			if (visit[e]) {
				printf("Gee");
			}
			else {
				printf("%lld",-D[e]);
			}
		}
		else {
			printf("%lld", -D[e]);
		}
	}
	
	
}