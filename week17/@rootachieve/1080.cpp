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
int map[52][52];
int target[52][52];
char arr[102];
queue<pair<int,int>> q;
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%s",arr);
		for (int j = 1; j <= m; j++) {
			map[i][j] = arr[j-1] -48;
		}
	}

	for (int i = 1; i <= n; i++) {
		scanf("%s", arr);
		for (int j = 1; j <= m; j++) {
			target[i][j] = arr[j - 1] - 48;
		}
	}
	int Count = 0;
	if (n >= 3 && m >= 3) {
		for (int i = 1; i <= n - 2; i++) {
			for (int j = 1; j <= m - 2; j++) {
				if (map[i][j] != target[i][j]) {
					Count++;
					for (int k = i; k <= i + 2; k++) {
						for (int g = j; g <= j + 2; g++) {
							map[k][g] = (map[k][g]+1)%2;
						}
					}
				}
			}
		}
	}
	bool err = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] != target[i][j]) {
				err = true;
				break;
			}
		}
	}

	if (err) {
		printf("-1");
	}else{
		printf("%d",Count);
	}
}