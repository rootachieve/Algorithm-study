#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include <bitset>
using namespace std;
int n,m;
vector<vector<int>> v;
int base[52];

bool compare(vector<int> a, vector<int>b) {
	return *max_element(a.begin(), a.end())< *max_element(b.begin(), b.end());
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &base[i]);
	}


	sort(base, base + n);
	
	int i = 0;
	while (i < n&&base[i]<0) {
		vector<int> c;

		int Count = 0;
		for (; Count<m; i++) {
			if (i == n||base[i]>0) {
				break;
			}
			c.push_back(abs(base[i]));
			Count++;
		}
		v.push_back(c);
	}
	int j = n - 1;
	while (j >= 0&&base[j]>0) {
		vector<int> c;

		int Count = 0;
		for (; Count < m; j--) {
			if (j == -1||base[j]<0) {
				break;
			}
			c.push_back(abs(base[j]));
			Count++;
		}
		v.push_back(c);
	}
	sort(v.begin(), v.end(), compare);
	int answer = 0;
	for (int i = 0; i < v.size()-1; i++) {
		answer += *max_element(v[i].begin(), v[i].end())*2;
	}
	answer += *max_element(v[v.size() - 1].begin(), v[v.size() - 1].end());
	printf("%d", answer);
}