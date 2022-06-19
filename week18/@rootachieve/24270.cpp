#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 1000001
#define MOD 1000000007
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)_((y)%MOD))%MOD
using namespace std;

int main(){
	ll a,b;
	cin>>a>>b;
	ll c;
	for(int i = 1;i<=a;i++){
		cin>>c;
		b-=c;
	}

	ll ans = 1;
	for (int i = b + 1; i <= a + b; i ++ ) {
		ans = MODULARF(ans,i);
	}

	cout<<ans%MOD;
}