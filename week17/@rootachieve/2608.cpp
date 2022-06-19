#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#define ll long long
#define MAX 2147483647
#define MOD 1000000000
#define MODULAR(x,y) (((x)%MOD)+((y)%MOD))%MOD
#define MODULARF(x,y) (((x)%MOD)*((y)%MOD))%MOD
#define MODULARM(x,y) (((x)%MOD)-((y)%MOD))%MOD
using namespace std;

pair<string,int> ty[] ={{"IX",9},{"IV",4},{"XL",40},{"XC",90},{"CD",400},
	{"CM",900}};
pair<string,int> ty2[] = {{"V",5},{"L",50},{"D",500},{"I",1},{"X",10},{"L",50},{"C",100},
		{"D",500},{"M",1000}};

string ch2(int a) {
	string ans = "";
	while (a != 0) {
		if (a >= 1000) {
			a-=1000;
			ans+="M";
		}
		else if (a >= 900) {
			a-=900;
			ans+="CM";
		}
		else if (a >= 500) {
			a-=500;
			ans+="D";
		}
		else if (a >= 400) {
			a -= 400;
			ans += "CD";
		}
		else if (a >= 100) {
			a -= 100;
			ans += "C";
		}
		else if (a >= 90) {
			a -= 90;
			ans += "XC";
		}
		else if (a >= 50) {
			a -= 50;
			ans += "L";
		}
		else if (a >= 40) {
			a -= 40;
			ans += "XL";
		}
		else if (a >= 10) {
			a -= 10;
			ans += "X";
		}
		else if (a >= 9) {
			a -= 9;
			ans += "IX";
		}
		else if (a >= 5) {
			a -= 5;
			ans += "V";
		}
		else if (a >= 4) {
			a -= 4;
			ans += "IV";
		}
		else {
			a-=1;
			ans+="I";
		}
	}
	return ans;
}

int ch(string a) {
	bool check = false;
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		check = false;
		if(i<a.size()-1){
			for (int j = 0; j < 6; j++) {
				if (a[i] == ty[j].first[0] && a[i + 1] == ty[j].first[1]) {
					check = true;
					sum+=ty[j].second;
					i++;
					break;
				}
			}
		}

		if (!check) {
			for (int j = 0; j < 9; j++) {
				if (a[i] == ty2[j].first[0]) {
					check = true;
					sum+=ty2[j].second;
					break;
				}
			}
		}
	}
		return sum;
}
string a,b;
int main() {
	cin>>a>>b;
	int sum = ch(a);
	sum += ch(b);

	cout<<sum<<endl;

	cout<<ch2(sum);
}