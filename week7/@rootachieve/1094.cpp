#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include <bitset>
using namespace std;
int n;

int main() {
	scanf("%d", &n);
	int i = 1;
	for (; i <= n;) {
		i *= 2;
	}
	int Count = 0;
	while (i > 0) {
		if (n - i >= 0) {
			n -= i;
			Count++;
		}
		i /= 2;
	}

	printf("%d", Count);
}