#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#define MOD 1000000007
#define MODUL(x,y) (((y)%MOD) + ((x)%MOD))%MOD

#define MODULF(x,y) (((y)%MOD) * ((x)%MOD))%MOD

using namespace std;

int t,n;

int arr[100002];
int Min = 0;
int main() {
	scanf("%d",&t);
	int a,b;
	for (int h = 1; h <= t; h++) {
		scanf("%d",&n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d",&a,&b);
			arr[a] = b;
		}
		int answer = 0;
		Min = n + 1;
		for (int i = 1; i <= n; i++) {
			if (Min > arr[i]) {
				answer++;
				Min = arr[i];
			}
		}
		printf("%d\n", answer);
	}
	
}