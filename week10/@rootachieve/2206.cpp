#include<stdio.h>
int N;
int M;//x y
char map[1002][1002];
int ans;
int count;

int Nqueue[2][1000000];//not wall
int NZ = -1;
int Nfront;
int NqueueoutX;
int NqueueoutY;
int Nvisi[1002][1002];
int Ncount[1000000];

int Wqueue[2][1000000];//wall
int WZ = -1;
int Wfront;
int WqueueoutX;
int WqueueoutY;
int Wvisi[1002][1002];
int Wcount[1000000];

int Ninqueue(int y, int x) {
	NZ++;
	Nqueue[0][Nfront + NZ] = y;
	Nqueue[1][Nfront + NZ] = x;
}
int Ndequeue() {
	if (NZ > -1) {
		NqueueoutX = Nqueue[1][Nfront];
		NqueueoutY = Nqueue[0][Nfront];
		Nfront++;
		NZ--;
	}
	else {
	}
}

int Winqueue(int y, int x) {
	WZ++;
	Wqueue[0][Wfront + WZ] = y;
	Wqueue[1][Wfront + WZ] = x;
}
int Wdequeue() {
	if (WZ > -1) {
		WqueueoutX = Wqueue[1][Wfront];
		WqueueoutY = Wqueue[0][Wfront];
		Wfront++;
		WZ--;
	}
	else {
	}
}
int main(){
	scanf("%d%d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		scanf("%s", &map[i]);
	}
	if (N == 1 && M == 1) {
		printf("1");
		return 0;
	}
	bfs();
}

int bfs() {
	Ninqueue(0, 0);
	Ncount[1]++;
	count++;
	while (ans == 0) {
		if (NZ == -1 && WZ == -1) {
			printf("-1");
			return 0;
		}
		Nbfs(count);
		Wbfs(count);
		count++;
	}
	printf("%d", count);
}





int Nbfs(int cou) {
	while (Ncount[cou] > 0) {
		Ndequeue();
		if (NqueueoutX != 0) {
			if (map[NqueueoutY][NqueueoutX - 1] == 48 && Nvisi[NqueueoutY][NqueueoutX - 1] == 0) {
				Nvisi[NqueueoutY][NqueueoutX - 1] = 1;
				Ninqueue(NqueueoutY, NqueueoutX - 1);
				Ncount[cou + 1]++;
				if (NqueueoutY == N-1 && NqueueoutX-1 == M-1) {
					ans = 1;
				}
			}
		}

		if (NqueueoutY != 0) {
			if (map[NqueueoutY - 1][NqueueoutX] == 48 && Nvisi[NqueueoutY - 1][NqueueoutX] == 0) {
				Nvisi[NqueueoutY - 1][NqueueoutX] = 1;
				Ninqueue(NqueueoutY - 1, NqueueoutX);
				Ncount[cou + 1]++;
				if (NqueueoutY-1 == N -1&& NqueueoutX == M-1) {
					ans = 1;
				}
			}
		}
		if (NqueueoutY < N - 1) {
			if (map[NqueueoutY + 1][NqueueoutX] == 48 && Nvisi[NqueueoutY + 1][NqueueoutX] == 0) {
				Nvisi[NqueueoutY + 1][NqueueoutX] = 1;
				Ninqueue(NqueueoutY + 1, NqueueoutX);
				Ncount[cou + 1]++;
				if (NqueueoutY+1 == N-1 && NqueueoutX == M-1) {
					ans = 1;
				}
			}
		}

		if (NqueueoutX < M - 1) {
			if (map[NqueueoutY][NqueueoutX + 1] == 48 && Nvisi[NqueueoutY][NqueueoutX + 1] == 0) {
				Nvisi[NqueueoutY][NqueueoutX + 1] = 1;
				Ninqueue(NqueueoutY, NqueueoutX + 1);
				Ncount[cou + 1]++;
				if (NqueueoutY == N-1 && NqueueoutX+1 == M-1) {
					ans = 1;
				}
			}
		}
		//--------------------------------------------------
		if (NqueueoutX >1) {
			if (map[NqueueoutY][NqueueoutX - 2] == 48&& map[NqueueoutY][NqueueoutX - 1] == 49 && Nvisi[NqueueoutY][NqueueoutX - 2] == 0) {
				Winqueue(NqueueoutY, NqueueoutX - 1);
				Wcount[cou + 1]++;
			}
		}

		if (NqueueoutY >1) {
			if (map[NqueueoutY - 2][NqueueoutX] == 48 &&map[NqueueoutY - 1][NqueueoutX] == 49 && Nvisi[NqueueoutY - 2][NqueueoutX] == 0) {
				Winqueue(NqueueoutY - 1, NqueueoutX);
				Wcount[cou + 1]++;
			}
		}
		if (NqueueoutY < N - 2) {
			if (map[NqueueoutY + 2][NqueueoutX] == 48&& map[NqueueoutY + 1][NqueueoutX] == 49 && Nvisi[NqueueoutY + 2][NqueueoutX] == 0) {
				Winqueue(NqueueoutY + 1, NqueueoutX);
				Wcount[cou + 1]++;
			}
		}

		if (NqueueoutX < M - 2) {
			if (map[NqueueoutY][NqueueoutX + 2] == 48&& map[NqueueoutY][NqueueoutX + 1] == 49 && Nvisi[NqueueoutY][NqueueoutX + 2] == 0) {
				Winqueue(NqueueoutY, NqueueoutX + 1);
				Wcount[cou + 1]++;
			}
		}

		Ncount[cou]--;
	}
	
}
int Wbfs(int cou) {
	while (Wcount[cou] > 0) {
		Wdequeue();
		if (WqueueoutX != 0) {
			if (map[WqueueoutY][WqueueoutX - 1] == 48 && Wvisi[WqueueoutY][WqueueoutX - 1] == 0) {
				Wvisi[WqueueoutY][WqueueoutX - 1] = 1;
				Winqueue(WqueueoutY, WqueueoutX - 1);
				Wcount[cou + 1]++;
				if (WqueueoutY == N-1 && WqueueoutX-1 == M-1) {
					ans = 1;
				}
			}
		}

		if (WqueueoutY != 0) {
			if (map[WqueueoutY - 1][WqueueoutX] == 48 && Wvisi[WqueueoutY - 1][WqueueoutX] == 0) {
				Wvisi[WqueueoutY - 1][WqueueoutX] = 1;
				Winqueue(WqueueoutY - 1, WqueueoutX);
				Wcount[cou + 1]++;
				if (WqueueoutY-1 == N-1 && WqueueoutX == M-1) {
					ans = 1;
				}
			}
		}
		if (WqueueoutY < N - 1) {
			if (map[WqueueoutY + 1][WqueueoutX] == 48&& Wvisi[WqueueoutY + 1][WqueueoutX] == 0) {
				Wvisi[WqueueoutY + 1][WqueueoutX] = 1;
				Winqueue(WqueueoutY + 1, WqueueoutX);
				Wcount[cou + 1]++;
				if (WqueueoutY+1 == N-1 && WqueueoutX == M-1) {
					ans = 1;
				}
			}
		}

		if (WqueueoutX < M - 1) {
			if (map[WqueueoutY][WqueueoutX + 1] == 48 && Wvisi[WqueueoutY][WqueueoutX + 1] == 0) {
				Wvisi[WqueueoutY][WqueueoutX + 1] = 1;
				Winqueue(WqueueoutY, WqueueoutX + 1);
				Wcount[cou + 1]++;
				if (WqueueoutY == N-1 && WqueueoutX+1 == M-1) {
					ans = 1;
				}
			}
		}
		Wcount[cou]--;
	}
	

}