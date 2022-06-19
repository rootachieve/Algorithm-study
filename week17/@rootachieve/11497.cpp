#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

vector<int> v1,v2,v3;
int ans;
int main() {
	int t;
	cin>>t;
	int n;
	int a;
	while (t--) {
		cin>>n;
		for (int i = 1; i <= n; i++) {
			cin>>a;
			v1.push_back(a);
		}

		sort(v1.begin(),v1.end());

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				v2.push_back(v1[i]);
			}
			else {
				v3.insert(v3.begin(),v1[i]);
			}
		}

		 v2.insert(v2.end(),v3.begin(),v3.end());
		 ans = abs(v2[0] - v2[n-1]);

		 for (int i = 0; i < n - 1; i++) {
			 ans = max(ans,abs(v2[i]-v2[i+1]));
		 }
		 printf("%d\n",ans);
		 v1.clear();
		 v2.clear();
		 v3.clear();
		 ans = 0;
	}
}