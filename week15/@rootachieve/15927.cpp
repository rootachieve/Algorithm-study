#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

string in;
bool Count[27];
int C = 0;
int main() {
	cin>>in;
	int n = in.length()-1;
	bool err = false;
	for (int i = 0; i <= n; i++) {
		if (in[i] != in[n - i]) {
			err = true;
			break;
		}
		else {
			if (Count[in[i] - 65] == 0) {
				C++;
				Count[in[i]- 65]=1;
			}
		}
	}

	if (err) {
		printf("%d",n+1);
	}
	else {
		if (C == 1) {
			printf("-1");
		}
		else {
			printf("%d",n);
		}
	}

}