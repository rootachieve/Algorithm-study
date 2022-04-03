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

vector<long long> w;
int n;
int main() {
	scanf("%d",&n);
	long long a;
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&a);
		w.push_back(a);
	}
	sort(w.begin(),w.end());
	long long sum = 0;
	for (int i = 0; i<w.size(); i++) {
		if (sum + 1 < w[i]) {
			break;
		}
		else {
			sum+=w[i];
		}
	}
	printf("%lld",sum+1);
}