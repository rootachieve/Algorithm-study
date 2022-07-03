#include <iostream>
#include <vector>
using namespace std;

int N, M;
int map[201][201] = { 0 };

vector<int> parent; //도시 별 최상위 도시
vector<int> path; //여행 경로

int fn_find(int node) {

    while (node != parent[node])
        node = parent[node];

    return node;
}

void fn_union(int x, int y) {

    x = fn_find(x);
    y = fn_find(y);

    if (x < y) parent[y] = x;
    else    parent[x] = y;
}

int main() {

    cin >> N >> M;

    parent = vector<int>(N + 1, 0);
    path = vector<int>(M + 1, 0);

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {

            scanf("%d", &map[i][j]);

            if (map[i][j])
                fn_union(i, j);
        }


    for (int i = 1; i <= M; i++)
        scanf("%d", &path[i]);


    bool check = true;
    for (int i = 1; i < M; i++) {
        if (fn_find(path[i]) != fn_find(path[i + 1])) {
            check = false;
            break;
        }
    }

    if (check)   cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
