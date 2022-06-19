#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;

char p[1000020];
int num[1000020];
int coun;
int z = 0;
int f;
bool isFlip;
void print() {
	if (isFlip) {
		if (z + 1 < f) {
			printf("[");
			for (int i = f - 1; i > z + 1; i--) {
				printf("%d,", num[i]);
			}
			printf("%d]\n", num[z + 1]);
		}
		else {
			printf("[]\n");
		}
	}
	else {
		if (z + 1 < f) {
			printf("[");
			for (int i = z + 1; i < f-1; i++) {
				printf("%d,", num[i]);
			}
			printf("%d]\n", num[f - 1]);
		}
		else {
			printf("[]\n");
		}
	}
}
bool D() {
	if (f == z+1) {
		printf("error\n");
		return true;
	}
	else {
		if (!isFlip) {
			z++;
		}
		else {
			f--;
		}
		return false;
	}
}

void R() {
	if (isFlip) {
		isFlip = false;
	}
	else {
		isFlip = true;
	}
}

void find(char a[]) {
	int i;
	int c = coun;
	int de = 1;
	for (i = 0; a[i] != 0; i++) {
		num[i] = 0;
	}
	for (; i >= 0; i--) {
		if (a[i] >= 48 && a[i] <= 57) {
			num[c] += (a[i] - 48) * de;
			de *= 10;
		}
		else {
			if (de >= 10) {
				de = 1;
				c--;
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	char a[1000000];
	char dummy;
	bool isE;
	for (int i = 1; i <= T; i++) {
		z = 0;
		isFlip = false;
		isE = false;
		scanf("%s", &p);
		scanf("%d", &coun);
		f = coun+1;
		scanf("%c", &dummy);
		scanf("%s", a);
		find(a);
		for(int j = 0; p[j] != 0; j++) {
			switch (p[j])
			{
				case 'R' :
					R();
					break;

				case 'D':
					isE = D();
					break;
			}

			if (isE) {
				break;
			}
		}
		if (!isE) {
			print();
		}
	}
}