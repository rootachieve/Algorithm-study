#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#define INF 987654321
using namespace std;

int n, m, testcase;
struct point {
	int x, y;
};
point p1;
point p2;
point p3;
pair<int, int> slope1;// first에는 기울기, second에는 전후관계
pair<int, int> slope2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;

	int result = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	result += -p1.y * p2.x - p2.y * p3.x - p3.y * p1.x;
	if (result > 0)
		cout << 1;
	else if (result < 0)
		cout << -1;
	else
		cout << 0;



	return 0;
}