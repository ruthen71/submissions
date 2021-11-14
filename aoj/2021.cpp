#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll INF = 1ll << 60;

void solve(ll N) {
    ll M, L, K, A, H;
    cin >> M >> L >> K >> A >> H;
    vector<int> c(N, 0);
    for (int i = 0; i < L; i++) {
        int x;
        cin >> x;
        c[x] = 1;
    }
    vector<vector<pair<int, ll>>> g(N);
    for (int i = 0; i < K; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        g[x].push_back({y, t});
        g[y].push_back({x, t});
    }
    int V = N * (M + 1);
    vector<vector<ll>> dist(N, vector<ll>(M + 1, INF));
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[A][M] = 0;
    pq.push({0, A * (M + 1) + M});
    while (!pq.empty()) {
        ll d = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        int cv = v / (M + 1), cm = v % (M + 1);
        if (dist[cv][cm] < d) continue;
        if (c[cv] && cm < M) {
            // 補給する
            if (dist[cv][cm + 1] > dist[cv][cm] + 1) {
                dist[cv][cm + 1] = dist[cv][cm] + 1;
                pq.push({dist[cv][cm + 1], cv * (M + 1) + cm + 1});
            }
        }
        for (auto &e : g[cv]) {
            if (cm - e.second >= 0 && dist[e.first][cm - e.second] > dist[cv][cm] + e.second) {
                dist[e.first][cm - e.second] = dist[cv][cm] + e.second;
                pq.push({dist[e.first][cm - e.second], e.first * (M + 1) + cm - e.second});
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i <= M; i++) ans = min(ans, dist[H][i]);
    if (ans == INF)
        puts("Help!");
    else
        cout << ans << endl;
    return;
}

int main() {
    ll n;
    while (cin >> n, n) solve(n);
    return 0;
}

/*
現在いる頂点と時間の猶予を持ってダイクストラ
*/