#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#define MOD 1000000007
#define MODUL(x,y) (((y)%MOD) + ((x)%MOD))%MOD

#define MODULF(x,y) (((y)%MOD) * ((x)%MOD))%MOD

using namespace std;
int dp[52];
char arr[51];
int main() {
	scanf("%s",arr);
	string s ="";
	for (int i = 0; arr[i] != NULL; i++) {
		s+=arr[i];
	}

	int l = s.size();
	string temp ="";
	for (int i = 0; i < l; i++) {
		bool err = false;
		for (int j = 0; j < l - i; j++) {
			if (s[i + j] != s[(l - 1) - j]) {
				err = true;
				break;
			}
		}

		if (!err) {
			s+=temp;
			break;
		}
		else {
			temp = s[i] + temp;
		}
	}


	printf("%d",s.size());
}