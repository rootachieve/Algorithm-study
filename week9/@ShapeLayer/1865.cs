using System;

public class Program
{
    const int INF = (int)2e9;
    public static void Main(string[] args)
    {
        int tc = int.Parse(Console.ReadLine());
        for (int tcn = 0; tcn < tc; tcn++)
        {
            int[] gets = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            int n = gets[0], m = gets[1], w = gets[2];
            int[] dist = new int[n+1];
            for (int i = 0; i < n+1; i++) dist[i] = INF;
            Tuple[] conns = new Tuple[2*m+w];
            for (int i = 0; i < m; i++) // Road
            {
                gets = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                conns[2*i] = new Tuple(gets[0], gets[1], gets[2]); // s, e, t
                conns[2*i+1] = new Tuple(gets[1], gets[0], gets[2]);
            }
            for (int i = 0; i < w; i++) // Wormhole
            {
                gets = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                conns[2*m+i] = new Tuple(gets[0], gets[1], gets[2]*-1); // s, e, t
            }
            bool isNCycle = false;
            dist[1] = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < 2*m+w; j++)
                {
                    int now = conns[j].s;
                    int next = conns[j].e;
                    int cost = conns[j].t;
                    if (dist[next] > dist[now] + cost)
                    {
                        dist[next] = dist[now] + cost;
                        if (i == n-1) isNCycle = true;
                    }
                }
            }
            if (isNCycle) Console.WriteLine("YES");
            else Console.WriteLine("NO");
        }
    }
}

public class Tuple
{
    public int s;
    public int e;
    public int t;
    public Tuple(int s, int e, int t)
    {
        this.s = s;
        this.e = e;
        this.t = t;
    }
}