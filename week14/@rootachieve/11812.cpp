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

ll n,k,m;
int main() {
	scanf("%lld%lld%lld",&n,&k,&m);

	if (k == 1) {
		ll a, b;
		for (int i = 1; i <= m; i++) {
			scanf("%lld%lld", &a, &b);
			printf("%lld\n",max(a,b)-min(a,b));
		}
	}else{
		ll a,b;
		for (int i = 1; i <= m; i++) {
			scanf("%lld%lld",&a,&b);
			unordered_map<ll,ll>m;
			int Count = 0;		
			while (1) {
				m.insert({a,Count});

				if (a == 1) {
					break;
				}
				Count++;
				a = (a-2)/k + 1;
			}

			Count = 0;
			while (1) {
				if (m.find(b) != m.end()) {
					Count+=m.find(b)->second;
					break;
				}
				Count++;
				b = (b-2)/k + 1;
			}

			printf("%lld\n",Count);
		}
	}
}