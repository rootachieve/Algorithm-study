#include <stdio.h>

int parents[201];

int find(int n) {
  if (n == parents[n]) return n;
  return find(parents[n]);
}
void merge(int a, int b) {
  int pa = find(a), pb = find(b);
  if (pa > pb) {
    parents[pa] = pb;
    parents[a] = pb;
  } else {
    parents[pb] = pa;
    parents[b] = pa;
  }
}

int main() {
  int n, m;
  int gets;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n+1; i++) parents[i] = i;
  for (int i = 1; i < n+1; i++) {
    for (int j = 1; j < n+1; j++) {
      scanf("%d", &gets);
      if (i == j) continue;
      if (gets) merge(i, j);
    }
  }
  int flag = 1;
  int init = -1;
  while (scanf("%d", &gets) != EOF) {
    if (init == -1) init = find(gets);
    else {
      if (init != find(gets)) flag = 0;
    }
  }
  if (flag) printf("YES\n");
  else printf("NO\n");
  return 0;
}