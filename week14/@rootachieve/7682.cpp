#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <deque>
#include <map>
#include <unordered_set>
#include <unordered_map>
#define MAX 1002147473647
#define MOD 100003
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

char in[10];

pair<int, int> countValidCheck() {
	int CountO = 0;
	int CountX = 0;
	for (int i = 0; i <= 8; i++) {
		if (in[i] == 'O') {
			CountO++;
		}
		else if (in[i] == 'X') {
			CountX++;
		}
	}
	return { CountO,CountX };

}

pair<int, int> cheinValidCheck() {
	int CountO = 0;
	int CountX = 0;
	for (int i = 0; i <= 2; i++) {
		if (in[0 + 3 * i] == in[1 + 3 * i] && in[1 + 3 * i] == in[2 + 3 * i]) {
			if (in[0 + 3 * i] == 'O') {
				CountO++;
			}
			else if (in[0 + 3 * i] == 'X') {
				CountX++;
			}
		}
	}

	for (int i = 0; i <= 2; i++) {
		if (in[0 + i] == in[3 + i] && in[3 + i] == in[6 + i]) {
			if (in[0 + i] == 'O') {
				CountO++;
			}
			else if (in[0 + i] == 'X') {
				CountX++;
			}
		}
	}

	if (in[0] == in[4] && in[4] == in[8]) {
		if (in[0] == 'O') {
			CountO++;
		}
		else if (in[0] == 'X') {
			CountX++;
		}
	}

	if (in[2] == in[4] && in[4] == in[6]) {
		if (in[6] == 'O') {
			CountO++;
		}
		else if(in[6] == 'X') {
			CountX++;
		}
	}

	return { CountO,CountX };
}
bool finishValidCheck() {
	pair<int,int> c = countValidCheck();

	if (c.second - c.first == 0 || c.second - c.first == 1) {
		if(c.second>=3){
			pair<int, int> d = cheinValidCheck();
		
			if (c.second - c.first == 0) {
				if (d.second == 0 && d.first == 1) {
					return true;
				}
			}
			else {
				if (d.second >= 1 && d.first == 0) {
					return true;
				}
				else if (c.second==5&&d.second == 0 && d.first == 0) {
					return true;
				}
			}
		}
	}

	return false;
}


int main() {
	while (1) {
		scanf("%s", &in);

		if (in[0] == 'e') {
			break;
		}

		if (finishValidCheck()) {
			printf("valid\n");
		}
		else {
			printf("invalid\n");
		}
	}
}