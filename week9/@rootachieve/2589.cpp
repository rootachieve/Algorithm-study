#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#define MAX 1002147473647
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;
int map[52][52];
int visit[52][52];
char arr[52];
int n,m;

queue<pair<int,int>> q;
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++){
		scanf("%s",&arr);
		for (int j = 1; j <= m; j++) {
			if (arr[j - 1] == 'L') {
				map[i][j] = 1;
			}
		}
	}
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {
				int target = visit[i][j] + 1;
				queue<pair<int,pair<int,int>>> q;
				visit[i][j] = target;
				q.push({0,{i,j}});
				int check = 0;
				while (!q.empty()) {
					int y = q.front().second.first;
					int x = q.front().second.second;
					int Count = q.front().first;
					check = max(check,Count);
					q.pop();
					if (map[y-1][x] == 1 && visit[y-1][x] != target) {
						visit[y-1][x] = target;
						q.push({Count+1,{y-1,x}});
					}

					if (map[y+1][x] == 1 && visit[y+1][x] != target) {
						visit[y+1][x] = target;
						q.push({ Count + 1,{y+1,x} });
					}

					if (map[y][x-1] == 1 && visit[y][x-1] != target) {
						visit[y][x-1] = target;
						q.push({ Count + 1,{y,x-1} });
					}

					if (map[y][x+1] == 1 && visit[y][x+1] != target) {
						visit[y][x+1] = target;
						q.push({ Count + 1,{y,x+1} });
					}

				}

				Max = max(check,Max);
			}
		}
	}


	printf("%d",Max);
	
}