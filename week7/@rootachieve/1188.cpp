#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include <bitset>
using namespace std;
int n, m;
int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}
int main() {
	scanf("%d%d", &n, &m);
	printf("%d", m - gcd(n, m));
}