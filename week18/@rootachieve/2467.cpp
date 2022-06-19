#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;
int a;
int b;
int n;
int sum;
int arr[100020];
int Max = 2000000020;
int findA;
int findB;


int abs(int num) {
	if (num < 0) {
		return -1 * num;
	}
	else {
		return num;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	a = 1;
	b = n;
	sum = arr[a] + arr[b];
	if (abs(sum) < Max) {
		Max = abs(sum);
		findA = arr[a];
		findB = arr[b];
	}

	while (a+1!=b) {
		if (sum < 0) {
			sum -= arr[a];
			a++;
			sum += arr[a];

			if (abs(sum) < Max) {
				Max = abs(sum);
				findA = arr[a];
				findB = arr[b];
			}
		}
		else {
			sum -= arr[b];
			b--;
			sum += arr[b];
			if (abs(sum) < Max) {
				Max = abs(sum);
				findA = arr[a];
				findB = arr[b];
			}
		}
	}
	printf("%d %d", findA, findB);
}
