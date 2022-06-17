#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include<cmath>
#include<cstring>
#include <bitset>
#include <stack>
#define DIV 1000000007
#define ll long long
#define MOD(x,y) (((x)%DIV)+((y)%DIV))%DIV
#define MODF(x,y) (((x)%DIV)*((y)%DIV))%DIV
#define MAX 1000000000000000
#define RESET 0
using namespace std;

ll s,t;
set<ll> S;
int main() {
	scanf("%lld%lld",&s,&t);
	queue<pair<ll,string>> q;
	q.push({s,""});
	string ans;

	if (s == t) {
		printf("0");
	}else{
		while (!q.empty()) {
			ll f = q.front().first;
			string str = q.front().second;
			q.pop();
			if (f > MAX) {
				continue;
			}
			if (f == t) {
				ans = str;
				break;
			}

			ll temp = f*f;
			if (S.find(temp) == S.end()) {
				S.insert(temp);
				q.push({temp,str+"*"});
			}

			temp = f + f;
			if (S.find(temp) == S.end()) {
				S.insert(temp);
				q.push({ temp,str + "+" });
			}

			temp = f - f;
			if (S.find(temp) == S.end()) {
				S.insert(temp);
				q.push({ temp,str + "-" });
			}
			if(f!=0){
				temp = f / f;
				if (S.find(temp) == S.end()) {
					S.insert(temp);
					q.push({ temp,str + "/" });
				}
			}
		}

		if (ans == "") {
			printf("-1");
		}
		else {
			cout<<ans;
		}
	}
}