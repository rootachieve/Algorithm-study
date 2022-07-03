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
using namespace std;

int n, m, testcase;
int big, small;
int mx[3] = { 0,0,0 };
int mn[3] = { 0,0,0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> mx[0] >> mx[1] >> mx[2];
    mn[0] = mx[0];
    mn[1] = mx[1];
    mn[2] = mx[2];
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        int tmp0, tmp2;
        cin >> a >> b >> c;
        tmp0 = mx[0];
        tmp2 = mx[2];
        mx[0] = max(mx[0], mx[1]) + a;
        mx[2] = max(mx[1], mx[2]) + c;
        mx[1] = max(max(tmp0, mx[1]), tmp2) + b;

        tmp0 = mn[0];
        tmp2 = mn[2];
        mn[0] = min(mn[0], mn[1]) + a;
        mn[2] = min(mn[1], mn[2]) + c;
        mn[1] = min(min(tmp0, mn[1]), tmp2) + b;
    }
    cout << max(max(mx[0], mx[1]), mx[2]) << " " << min(min(mn[0], mn[1]), mn[2]);

    return 0;
}