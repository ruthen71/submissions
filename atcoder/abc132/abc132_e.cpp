#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int INF = 1 << 30;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dist(N, vector<int>(3, INF));
    vector<vector<int>> g(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    int S, T;
    cin >> S >> T;
    S--, T--;
    dist[S][0] = 0;
    queue<int> que;
    que.push(3 * S + 0);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        int v = x / 3, st = x % 3;
        for (auto &nx : g[v]) {
            if (dist[nx][(st + 1) % 3] == INF) {
                dist[nx][(st + 1) % 3] = dist[v][st] + 1;
                que.push(nx * 3 + (st + 1) % 3);
            }
        }
    }
    cout << ((dist[T][0] == INF) ? -1 : dist[T][0] / 3) << '\n';
    return 0;
}

/**
 * 頂点を3倍にしてBFS
 */