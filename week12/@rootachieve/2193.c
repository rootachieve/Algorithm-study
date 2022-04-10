#include<stdio.h>
unsigned long long pi[100];
int N;
int main() {
	pi[1] = 1;
	pi[2] = 1;
	scanf("%d", &N);
	for (int i = 3; i <= N; i++) {
		pi[i] = pi[i - 1] + pi[i - 2];
	}
	printf("%llu", pi[N]);

}