#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int map[320][320];
int n, m;
int Count;
queue <pair<int, int>> q;
int visit[320][320];
int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0) {
				Count++;
			}
		}
	}
	int now = 0;
	int year = 0;
	bool ch;
	do {
		year++;
		if (Count == 0) {
			year = 1;
			break;
		}
		now = 0;
		ch = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] != 0) {
					q.push(make_pair(i, j));
					visit[i][j] = year;
					ch = true;
					queue <pair<int, int>> del;
					while (!q.empty()) {
						
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						now++;
						if (map[y - 1][x] == 0) {
							map[y][x]--;
						}
						else if (map[y - 1][x] != 0 && visit[y - 1][x] != year) {
							visit[y - 1][x] = year;
							q.push(make_pair(y - 1, x));
						}

						if (map[y][x - 1] == 0) {
							map[y][x]--;
						}
						else if (map[y][x - 1] != 0 && visit[y][x - 1] != year) {
							visit[y][x - 1] = year;
							q.push(make_pair(y, x - 1));
						}

						if (map[y + 1][x] == 0) {
							map[y][x]--;
						}
						else if (map[y + 1][x] != 0 && visit[y + 1][x] != year) {
							visit[y + 1][x] = year;
							q.push(make_pair(y + 1, x));
						}

						if (map[y][x + 1] == 0) {
							map[y][x]--;
						}
						else if (map[y][x + 1] != 0 && visit[y][x + 1] != year) {
							visit[y][x + 1] = year;
							q.push(make_pair(y, x + 1));
						}


						if (map[y][x] <= 0) {
							map[y][x] = -1;
							del.push(make_pair(y, x));
						}
					}

					while (!del.empty()) {
						map[del.front().first][del.front().second] = 0;
						now--;
						del.pop();
						Count--;
					}
					
					break;
				}
			}
			if (ch) {
				break;
			}
		}
	} while (now == Count);

	printf("%d", year-1);
}