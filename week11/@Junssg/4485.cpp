#include<iostream>
#include<queue>

#define endl "\n"
#define MAX 130
#define INF 987654321
using namespace std;

int N, Answer;
int MAP[MAX][MAX];
int Dist[MAX][MAX];
bool Inp_Flag;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void Initialize()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            Dist[i][j] = INF;
        }
    }
}

void Input()
{
    cin >> N;
    if (N == 0)
    {
        Inp_Flag = true;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}

void Solution()
{
    priority_queue<pair<int, pair<int, int>>> PQ;
    PQ.push(make_pair(-MAP[0][0], make_pair(0, 0)));
    Dist[0][0] = MAP[0][0];

    while (PQ.empty() == 0)
    {
        int Cost = -PQ.top().first;
        int x = PQ.top().second.first;
        int y = PQ.top().second.second;
        PQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                int nCost = Cost + MAP[nx][ny];
                if (Dist[nx][ny] > nCost)
                {
                    Dist[nx][ny] = nCost;
                    PQ.push(make_pair(-Dist[nx][ny], make_pair(nx, ny)));
                }
            }
        }
    }
    Answer = Dist[N - 1][N - 1];
}

void Solve()
{
    int Tc = 1;
    for (int T = 1; ; T++)
    {
        Initialize();
        Input();
        if (Inp_Flag == true) return;
        Solution();

        cout << "Problem " << T << ": " << Answer << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}

