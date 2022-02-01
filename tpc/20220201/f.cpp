#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
const ll INF = 1ll << 60;

vector<ll> dijkstra(vector<vector<pair<int, int>>> &GRAPH, int S, ll st, vector<ll> &t0, vector<ll> &p, vector<ll> &d) {
    int V = GRAPH.size();
    vector<ll> dist(V, INF);
    dist[S] = st;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push({st, S});
    while (!que.empty()) {
        auto q = que.top();
        que.pop();
        int v = q.second;
        if (dist[v] < q.first) continue;
        for (auto &es : GRAPH[v]) {
            ll ct = dist[v];
            ll dt;
            if (ct <= t0[es.second]) {
                dt = t0[es.second];
            } else {
                dt = (ct - t0[es.second] + p[es.second] - 1) / p[es.second] * p[es.second] + t0[es.second];
            }
            if (dist[es.first] > dt + d[es.second]) {
                dist[es.first] = dt + d[es.second];
                que.push({dist[es.first], es.first});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, M, S;
    cin >> N >> M >> S;
    vector<vector<pair<int, int>>> G(N);
    vector<int> u(M), v(M);
    vector<ll> t0(M), p(M), d(M);
    rep(i, M) cin >> u[i] >> v[i] >> t0[i] >> p[i] >> d[i];
    rep(i, M) G[u[i]].push_back({v[i], i});
    if (dijkstra(G, 0, 0, t0, p, d)[N - 1] > S) {
        cout << "impossible\n";
        return 0;
    }
    ll ok = 0, ng = INF;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (dijkstra(G, 0, mid, t0, p, d)[N - 1] <= S)
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << '\n';
    return 0;
}

/**
 * 二分探索+Dijkstra法
 */
