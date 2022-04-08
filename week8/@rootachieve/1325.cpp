#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include <bitset>
#include <string>
using namespace std;
int n,m;
int visit[10001];
queue <int> q;
vector<int> v[10001];
vector<int> ans;
int main() {
	scanf("%d%d",&n,&m);
	int a, b;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d",&a,&b);
		v[b].push_back(a);
	}
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		int Count = 0;
		visit[i] = i;
		q.push(i);
		while (!q.empty()) {
			int node = q.front();
			Count++;
			q.pop();
			for (int j = 0; j < v[node].size(); j++) {
				if (visit[v[node][j]] != i) {
					visit[v[node][j]] = i;
					q.push(v[node][j]);
				}
			}
		}
		if (Max == Count) {
			ans.push_back(i);
		}
		else if (Max < Count) {
			Max =Count;
			ans.clear();
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {

		printf("%d ", ans[i]);
	}
}