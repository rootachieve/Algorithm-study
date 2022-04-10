#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int ccw(pair<int, int> a, pair<int, int>b, pair<int, int>c) {
	int op = a.first * b.second + c.first * a.second + b.first * c.second;
	op -= (b.first * a.second + a.first * c.second + c.first * b.second);
	if (op > 0) return 1;
	else if (op == 0) return 0;
	else return -1;
}

int a1, b1, a2, b2, a3, b3;

int main() {
	scanf("%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3);

	int ans = ccw(make_pair(a1, b1), make_pair(a2, b2), make_pair(a3, b3));
	printf("%d",ans);
}