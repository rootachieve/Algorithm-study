import java.util.Scanner;
import java.util.ArrayList;

public class Main {
  public static final long INF = Long.MAX_VALUE;
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt(), initCity = sc.nextInt(), finCity = sc.nextInt(), m = sc.nextInt();
    ArrayList<Tuple> conns = new ArrayList<Tuple>();
    long[] earnAtCity = new long[n];
    long[] earns = new long[n]; // reverse needed
    for (int i = 0; i < m; i++)
      conns.add(new Tuple(sc.nextInt(), sc.nextInt(), sc.nextInt()));
    for (int i = 0; i < n; i++) {
      earnAtCity[i] = sc.nextInt();
      earns[i] = -INF;
    }
    // earns[initCity]는 0 대신 earnAtCity[initCity]로 초기화함
    // 이유: 예제 입력 5 상황에서 루프 돌지 않고 그대로 처리가 끝나버림
    // 논리적으로도 0으로 초기화할 때는 시작부분이라 코스트가 없다는 걸 의미하는것
    // 이 문제에서는 시작부분에서도 돈을 벌기 때문에 0으로 초기화하는것은 부적절함
    earns[initCity] = earnAtCity[initCity];
    for (int i = 0; i < n + 100; i++) {
      for (int j = 0; j < m; j++) {
        Tuple now = conns.get(j);
        long offset = -now.val + earnAtCity[now.f];
        // 시작 노드가 INF라면 처리를 계속 진행하지 않음
        // 만약 출발지-도착지에서 닿을 수 없는 노드에서 음수 사이클이 발생한다면 Gee로 처리되기 때문
        if (earns[now.i] == -INF) continue;
        else if (earns[now.i] == INF) earns[now.f] = INF;
        else if (earns[now.f] < earns[now.i] + offset) {
          earns[now.f] = earns[now.i] + offset;
          if (i >= n-1) earns[now.f] = INF;
        }
      }
    }
    if (earns[finCity] == -INF) {
      System.out.println("gg");
    } else if (earns[finCity] == INF) {
      System.out.println("Gee");
    } else {
      System.out.println(earns[finCity]);
    }
  }
}

class Tuple {
  public int i;
  public int f;
  public int val;
  public Tuple(int i, int f, int val) {
    this.i = i;
    this.f = f;
    this.val = val;
  }
}