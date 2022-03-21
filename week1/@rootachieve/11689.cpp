#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define IMAX 2147483647
using namespace std;

long long g[100020];
long long m;
long long n;
int Count;
void get_G(long long a) {
	long long num = a;
	long long k = 2;
	while (k*k <= a) {
		while (num % k == 0) {
			g[Count++] = k;
			num /= k;
		}
		k++;
	}
	if (num > 1) {
		g[Count++] = num;
	}
}

long long gcd(long long a, long long b) {
	return a % b ? gcd(b, a % b): b;
}

int main() {
	scanf("%lld", &n);
	get_G(n);

	printf("");
	m = 1;
	for (int i = 0; i < Count;) {
		int index = upper_bound(g, g + Count, g[i]) - g;
		index--;
		m *= (g[i] - 1) * pow(g[i],(index - i));
		i = ++index;
	}

	printf("%lld",m);
}