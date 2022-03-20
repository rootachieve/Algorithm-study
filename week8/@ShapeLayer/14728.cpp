#include <iostream>
#include <vector>
#define max(a, b) (a > b ? a: b)
using namespace std;

int main() {
  int n,t ;
  cin >> n >> t;
  int times[1000], scores[1000];
  vector<vector<int> > table(1001, vector<int> (10001, 0));
  for (int i = 0; i < 1001; i++) table[i][0] = 0;
  for (int i = 0; i < 10001; i++) table[0][i] = 0;
  for (int i = 0; i < n; i++) cin >> times[i] >> scores[i];
  for (int i = 1; i < n+1; i++) {
    for (int j = 1; j < t+1; j++) {
      if (times[i-1] <= t && j >= times[i-1]) {
        table[i][j] = max(
          table[i-1][j-times[i-1]] + scores[i-1],
          table[i-1][j]
        );
      } else {
        table[i][j] = table[i-1][j];
      }
    }
  }
  cout << table[n][t] << endl;
}