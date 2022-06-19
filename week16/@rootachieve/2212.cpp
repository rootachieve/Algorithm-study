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
int base[10002];
vector<int> v;
int n,k;

int main() {
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; i++) {
		scanf("%d",&base[i]);
	}
	sort(base,base+n);
	for (int i = 0; i < n - 1; i++) {
		v.push_back(base[i+1]-base[i]);
	}

	for (int i = 1; i < k; i++) {
		vector<int>::iterator iter = max_element(v.begin(), v.end());
		if(iter!=v.end()){
		v.erase(iter);
		}
	}
	long long ans = 0;
	for (int i = 0; i < v.size(); i++) {
		ans+=v[i];
	}

	printf("%lld",ans);


}