#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include <bitset>
#include <string>
using namespace std;

int n,target;

int main() {
	scanf("%d%d",&n,&target);
	int Count = 0;
	bool err = false;
	do{
		Count++;
		if (target % 2 == 0) {
			target/=2;
		}
		else {
			if (target % 10 == 1) {
				target/=10;
			}
			else {
				err = true;
			}
		}
	}while(!err&&target>n);

	if (n == target) {
		printf("%d",Count+1);
	}
	else {
		printf("-1");
	}
}