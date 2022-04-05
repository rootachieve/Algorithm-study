#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <algorithm>
#include <queue>
using namespace std;

vector <int>* graph;
int T;
int N;//node
int K;//edge
int D[1020];
int able[1020];
int Dlay[1020];
int W;//target
int main() {
	scanf("%d", &T);
	for (int u = 1; u <= T; u++) {
		queue<int> q;
		scanf("%d%d", &N, &K);
		int m;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &m);
			Dlay[i] = 0;
			able[i] = 0;
			D[i] = m;
		}
		graph = new vector <int>[N + 1];
		int n;
		for (int i = 1; i <= K; i++) {
			scanf("%d%d", &m, &n);
			graph[m].push_back(n);
			able[n]++;
		}
		scanf("%d", &W);
		for (int i = 1; i <= N; i++) {
			
			if (able[i] == 0) {
				q.push(i);
				Dlay[i] = D[i];
			}
		}
		while (!q.empty()) {
			int a = q.front();
			q.pop();
			for (int i = 0; i<graph[a].size(); i++) {
				if (Dlay[graph[a][i]] < Dlay[a] + D[graph[a][i]]) {
					Dlay[graph[a][i]] = Dlay[a] + D[graph[a][i]];
				}
				able[graph[a][i]]--;
				if (able[graph[a][i]] == 0) {
					q.push(graph[a][i]);
				}
			}
		}

		printf("%d\n", Dlay[W]);

	}
}