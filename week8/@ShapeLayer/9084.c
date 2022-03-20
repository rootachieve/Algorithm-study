#include <stdio.h>

int main()
{
  int t;
  scanf("%d", &t);
  int coin[21];
  for (int i = 0; i < 21; i++) coin[i] = 0;

  for (int i = 0; i < t; i++)
  {
    int n, m;
    scanf("%d", &n);

    for (int j = 1; j < n+1; j++) scanf("%d", &coin[j]);
    scanf("%d", &m);

    int d[10001];
    for (int j = 1; j < 10001; j++) d[j] = 0;
    d[0] = 1;

    for (int a = 1; a < n+1; a++)
      for (int b = coin[a]; b < m+1; b++)
        if (b - coin[a] >= 0)
          d[b] += d[b - coin[a]];
    
    printf("%d\n", d[m]);
  }
  return 0;
}