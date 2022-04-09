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
int n,k;
int base[22];
int back(int a, int b, int now) {
	if (now == k) {
		return 0;
	}
	else {
		int l = back(base[now],b,now+1);
		int r = back(a,base[now],now+1);
		return min(l+abs(a-base[now]),r+abs(b-base[now]));
	}
}

int main() {
int a,b;
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	scanf("%d",&k);
	for (int i = 0; i < k; i++) {
		scanf("%d",&base[i]);
	}
	printf("%d",back(a,b,0));

}