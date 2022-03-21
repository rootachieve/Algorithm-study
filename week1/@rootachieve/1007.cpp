#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define IMAX 2147483647
using namespace std;

int t;
pair<long long, long long> base[22];
int n;
double ans;
pair<long long,long long> temp;


void Back(int w, int Count) {
	if (Count*2 == n) {
		if (ans > sqrt((double)pow(temp.first, 2) + (double)pow(temp.second, 2))) ans = sqrt(pow(temp.first, 2) + pow(temp.second, 2));
	}
	else {
		for (int i = w; i <= n; i++) {
			temp.first -= (base[i].first * 2);
			temp.second -= (base[i].second * 2);
			Back(i + 1, Count + 1);
			temp.first += (base[i].first * 2);
			temp.second += (base[i].second * 2);
		}
	}
}

int main() {
	scanf("%d", &t);
	long long a, b;
	for (int h = 1; h <= t; h++) {
		scanf("%d", &n);
		ans = IMAX;
		temp.first = 0;
		temp.second = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld", &a, &b);
			base[i] = make_pair(a, b);
			temp.first += a;
			temp.second += b;
		}

		Back(1, 0);
		
		
		printf("%lf\n",ans);

	}
}