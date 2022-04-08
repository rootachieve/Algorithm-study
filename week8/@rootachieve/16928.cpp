#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include <bitset>
#include <string>
#include <deque>
using namespace std;

vector<int> v[107];
int visit[107];
int n,m;
deque<int> q;
int main() {
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 6; j++) {
			v[i].push_back(i + j);
			visit[i] = 1000;
		}
	}
	for (int i = 1; i <= n + m; i++) {
		scanf("%d%d",&a,&b);
		v[a].clear();
		v[a].push_back(b);
	}
	visit[1] = 1;
	q.push_back(1);
	while (!q.empty()) {
		int node = q.front();
		q.pop_front();
		if (v[node].size() == 1) {
			if (visit[node]< visit[v[node][0]]) {
				visit[v[node][0]] = visit[node];
				q.push_front(v[node][0]);
			}
		}else{
			for (int i = 0; i < v[node].size(); i++) {
				if (visit[v[node][i]]> visit[node] + 1) {
					visit[v[node][i]] = visit[node]+1;
					q.push_back(v[node][i]);
				}
			}
		}
	}
	printf("%d",visit[100]-1);
	
}