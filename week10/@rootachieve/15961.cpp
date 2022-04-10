#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#define MAX 100000000001;
#define MOD 10007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

int n,d,k,c;
vector<int> temp;
vector<int> v;
int check[3002];
int Count = 1;
int type = 0;
int main() {
	scanf("%d%d%d%d",&n,&d,&k,&c);
	int h;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&h);
		temp.push_back(h);
	}

	v.insert(v.end(), temp.begin(), temp.end());
	v.insert(v.end(), temp.begin(), temp.end());
	int a = 0;
	int b = 0;

	for (; b < k;b++) {
		if (++check[v[b]] == 1) {
			type++;
		}
	}
	b--;
	int Max = 0;
	for (; a < n;) {
		if (check[c] == 0) {
			Max = max(Max,type+1);
		}
		else {
			Max = max(Max, type);
		}
		
		if (--check[v[a]] == 0) {
			type--;
		}
		a++;
		b++;
		if (++check[v[b]] == 1) {
			type++;
		}
	
	}
	printf("%d",Max);
}