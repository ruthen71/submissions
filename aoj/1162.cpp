#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const ll INF = 1ll << 60;

const int V = 30;
ld dist[30][30][V + 1];

int solve(int N, int M) {
    int S, G;
    cin >> S >> G;
    S--, G--;
    vector<vector<tuple<int, int, int>>> Graph(N);
    rep(i, M) {
        int u, v, d, c;
        cin >> u >> v >> d >> c;
        u--, v--;
        Graph[u].push_back({v, d, c});
        Graph[v].push_back({u, d, c});
    }
    rep(i, N) rep(j, N) rep(k, V + 1) dist[i][j][k] = INF;
    rep(i, N) dist[S][i][0] = 0;
    priority_queue<pair<ld, tuple<int, int, int>>, vector<pair<ld, tuple<int, int, int>>>, greater<pair<ld, tuple<int, int, int>>>> pq;
    rep(i, N) pq.push({0, {S, i, 0}});
    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        ld d = v.first;
        tuple<int, int, int> x = v.second;
        int xi = get<0>(x), xj = get<1>(x), xv = get<2>(x);
        if (d > dist[xi][xj][xv]) continue;
        for (auto &nx : Graph[get<0>(x)]) {
            if (get<0>(nx) == xj) continue;
            for (int dv = -1; dv <= 1; dv++) {
                if (xv + dv < 0) continue;
                if (get<2>(nx) >= xv + dv) {
                    if (dist[get<0>(nx)][xi][xv + dv] > dist[xi][xj][xv] + (ld)(get<1>(nx)) / (xv + dv)) {
                        dist[get<0>(nx)][xi][xv + dv] = dist[xi][xj][xv] + (ld)(get<1>(nx)) / (xv + dv);
                        pq.push({dist[get<0>(nx)][xi][xv + dv], {get<0>(nx), xi, xv + dv}});
                    }
                }
            }
        }
    }
    ld ans = INF;
    rep(i, N) ans = min(ans, dist[G][i][1]);
    if (ans == INF) return puts("unreachable") & 0;
    printf("%.15Lf\n", ans);
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    while (cin >> N >> M, N | M) solve(N, M);
    return 0;
}

/**
 * 頂点増やしてDijkstra法
 */
