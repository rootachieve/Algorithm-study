#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;
int arr[12];


struct info {
	int m, n, o, p, q, r, s, t, u, v, w;

	info(int M, int N, int O, int P, int Q, int R, int S, int T, int U, int V, int W) {
		m = M;
		n = N;
		o = O;
		p = P;
		q = Q;
		r = R;
		s = S;
		t = T;
		u = U;
		v = V;
		w = W;
	}
};
queue<info> que;

int a;
int Count = 0;
int b [22][12] = {{1,0,0,0,0,0,0,0,0,0,0},{ -1,0,0,0,0,0,0,0,0,0,0 },
			{ 0,1,0,0,0,0,0,0,0,0,0 },{ 0,-1,0,0,0,0,0,0,0,0,0 },
			{ 0,0,1,0,0,0,0,0,0,0,0 },{ 0,0,-1,0,0,0,0,0,0,0,0 },
			{ 0,0,0,1,0,0,0,0,0,0,0 },{ 0,0,0,-1,0,0,0,0,0,0,0 },
			{ 0,0,0,0,1,0,0,0,0,0,0 },{ 0,0,0,0,-1,0,0,0,0,0,0 },
			{ 0,0,0,0,0,1,0,0,0,0,0 },{ 0,0,0,0,0,-1,0,0,0,0,0 },
			{ 0,0,0,0,0,0,1,0,0,0,0 },{ 0,0,0,0,0,0,-1,0,0,0,0 },
			{ 0,0,0,0,0,0,0,1,0,0,0 },{ 0,0,0,0,0,0,0,-1,0,0,0 },
			{ 0,0,0,0,0,0,0,0,1,0,0 },{ 0,0,0,0,0,0,0,0,-1,0,0 },
			{ 0,0,0,0,0,0,0,0,0,1,0 },{ 0,0,0,0,0,0,0,0,0,-1,0 },
			{ 0,0,0,0,0,0,0,0,0,0,1 },{ 0,0,0,0,0,0,0,0,0,0,-1 } };

int main() {

	int m, n, o, p, q, r, s, t, u, v, w;
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5] >>
		arr[6] >> arr[7] >> arr[8] >> arr[9] >> arr[10];

	int*********** map = (int***********)malloc(sizeof(int**********) * (arr[0] ));
	for (m = 0; m < arr[0] ; m++) {
		map[m] = (int**********)malloc(sizeof(int*********) * (arr[1] ));
		for (n = 0; n < arr[1] ; n++) {
			map[m][n] = (int*********)malloc(sizeof(int********) * (arr[2] ));
			for (o = 0; o < arr[2] ; o++) {
				map[m][n][o] = (int********)malloc(sizeof(int*******) * (arr[3] ));
				for (p = 0; p < arr[3] ; p++) {
					map[m][n][o][p] = (int*******)malloc(sizeof(int******) * (arr[4] ));
					for (q = 0; q < arr[4] ; q++) {
						map[m][n][o][p][q] = (int******)malloc(sizeof(int*****) * (arr[5] ));
						for (r = 0; r < arr[5] ; r++) {
							map[m][n][o][p][q][r] = (int*****)malloc(sizeof(int****) * (arr[6] ));
							for (s = 0; s < arr[6] ; s++) {
								map[m][n][o][p][q][r][s] = (int****)malloc(sizeof(int***) * (arr[7] ));
								for (t = 0; t < arr[7] ; t++) {
									map[m][n][o][p][q][r][s][t] = (int***)malloc(sizeof(int**) * (arr[8] ));
									for (u = 0; u < arr[8] ; u++) {
										map[m][n][o][p][q][r][s][t][u] = (int**)malloc(sizeof(int*) * (arr[9] ));
										for (v = 0; v < arr[9] ; v++) {
											map[m][n][o][p][q][r][s][t][u][v] = (int*)malloc(sizeof(int) * (arr[10] ));
											for (w = 0; w < arr[10] ; w++) {
												map[m][n][o][p][q][r][s][t][u][v][w] = -1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (w = 0; w < arr[10]; w++) {
		for (v = 0; v < arr[9]; v++) {
			for (u = 0; u < arr[8]; u++) {
				for (t = 0; t < arr[7]; t++) {
					for (s = 0; s < arr[6]; s++) {
						for (r = 0; r < arr[5]; r++) {
							for (q = 0; q < arr[4]; q++) {
								for (p = 0; p < arr[3]; p++) {
									for (o = 0; o < arr[2]; o++) {
										for (n = 0; n < arr[1]; n++) {
											for (m = 0; m < arr[0]; m++) {
												scanf("%d", &a);

												if (a == 1) {
													map[m][n][o][p][q][r][s][t][u][v][w] = 1;
													que.push(info(m, n, o, p, q, r, s, t, u, v, w));
													
												}
												else if (a == 0) {
													map[m][n][o][p][q][r][s][t][u][v][w] = 0;
													Count++;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	

	int Time;
	int Max = 1;
	while (!que.empty()) {
		if (Count == 0) {
			break;
		}
		m = que.front().m;
		n = que.front().n;
		o = que.front().o;
		p = que.front().p;
		q = que.front().q;
		r = que.front().r;
		s = que.front().s;
		t = que.front().t;
		u = que.front().u;
		v = que.front().v;
		w = que.front().w;
		Time = map[m][n][o][p][q][r][s][t][u][v][w];
		que.pop();

		for (int i = 0; i < 22; i++) {
			if (m + b[i][0] < arr[0] && n + b[i][1] < arr[1] && o + b[i][2] < arr[2] && p + b[i][3] < arr[3] && q + b[i][4] < arr[4] && r + b[i][5] < arr[5] &&
				s + b[i][6] < arr[6] && t + b[i][7] < arr[7] && u + b[i][8] < arr[8] && v + b[i][9] < arr[9] && w + b[i][10] < arr[10]) {
				if (m + b[i][0] >= 0 && n + b[i][1] >= 0 && o + b[i][2] >= 0 && p + b[i][3] >= 0 && q + b[i][4] >= 0 && r + b[i][5] >= 0 &&
					s + b[i][6] >= 0 && t + b[i][7] >= 0 && u + b[i][8] >= 0 && v + b[i][9] >= 0 && w + b[i][10] >= 0) {
					if (map[m + b[i][0]][n + b[i][1]][o + b[i][2]][p + b[i][3]][q + b[i][4]][r + b[i][5]][s + b[i][6]][t + b[i][7]][u + b[i][8]][v + b[i][9]][w + b[i][10]] == 0) {
						map[m + b[i][0]][n + b[i][1]][o + b[i][2]][p + b[i][3]][q + b[i][4]][r + b[i][5]][s + b[i][6]][t + b[i][7]][u + b[i][8]][v + b[i][9]][w + b[i][10]] = Time + 1;
						que.push(info(m + b[i][0], n + b[i][1], o + b[i][2], p + b[i][3], q + b[i][4], r + b[i][5], s + b[i][6], t + b[i][7], u + b[i][8], v + b[i][9], w + b[i][10]));
						Count--;
						Max = max(Max, Time + 1);
					}
				}
			}
		}
	}

	if (Count == 0) {
		printf("%d",Max-1);
	}
	else {
		printf("-1");
	}

	free(map);
}