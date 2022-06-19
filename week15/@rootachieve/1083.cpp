#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_map>
#include <cstring>
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
#define ll long long
using namespace std;

int n, s, v[53];

int main() 
{ 
	scanf("%d", &n); 
	for (int i = 0; i < n; i++){ 
		scanf("%d", &v[i]);
	}
	scanf("%d", &s); 

	for (int i = 0; i < n && s; i++) 
	{ 
		int max = v[i];
		int index = i; 
		for (int j = i + 1; j < n && j <= i + s; j++){
			if (max < v[j]){
				max = v[j];
				index = j;
			}
		}
		s -= (index - i);
		while (index > i){
			v[index] = v[index - 1];
			index--;
		}
		v[i] = max; 
	} 
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
}