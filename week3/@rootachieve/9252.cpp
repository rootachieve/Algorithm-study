#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int map[1020][1020];
char A[1020];
char B[1020];
stack <char> s;
int main() {
	scanf("%s", &A);
	scanf("%s", &B);
	int i;
	int j;
	for (i = 1; B[i - 1] != NULL; i++) {
		for (j = 1; A[j - 1] != NULL; j++) {
			if (A[j-1] == B[i-1]) {
				map[i][j] = max(max(map[i - 1][j], map[i][j - 1]), map[i - 1][j - 1] + 1);
			}
			else {
				map[i][j] = max(map[i - 1][j], map[i][j - 1]);
			}
		}
	}
	printf("%d\n", map[i - 1][j - 1]);

	if (map[i - 1][j - 1] != 0) {
		int n, m;
		n = i - 1;
		m = j - 1;
		for (int g = map[i - 1][j - 1]; g >= 1; g--) {
			while (map[n - 1][m] == g || map[n][m - 1] == g) {
				if (map[n - 1][m] == g) {
					n--;
				}
				else if (map[n][m - 1] == g) {
					m--;
				}
			}
			s.push(A[m - 1]);
			m--;
			n--;
		}

		while (!s.empty()) {
			printf("%c", s.top());
			s.pop();
		}
	}
}