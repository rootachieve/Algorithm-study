import java.util.Scanner;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt(), m = sc.nextInt();
    boolean[][] table = new boolean[n+1][n+1];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) table[i][j] = true;
        else table[i][j] = false;
      }
    }
    for (int i = 0; i < m; i++) {
      int h = sc.nextInt(), l = sc.nextInt();
      table[h][l] = true;
    }
    /* Wrong Answer
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
    */
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (!table[i][j]) {
            if (table[i][k] && table[k][j]) {
              table[i][j] = true;
            }
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      int cnt = 0;
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        if (table[i][j] || table[j][i]) cnt++;
      }
      System.out.println(n - cnt - 1);
    }
  }
}
