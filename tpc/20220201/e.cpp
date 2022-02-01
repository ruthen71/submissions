#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
const ll INF = 1ll << 60;

vector<ll> dijkstra(vector<vector<pair<int, ll>>> &GRAPH, int V, int S) {
    vector<ll> dist(V, INF);
    dist[S] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.push({0, S});

    while (!que.empty()) {
        pair<ll, int> p = que.top();
        que.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0; i < GRAPH[v].size(); i++) {
            pair<int, ll> edge = GRAPH[v][i];
            if (dist[edge.first] > dist[v] + edge.second) {
                dist[edge.first] = dist[v] + edge.second;
                que.push({dist[edge.first], edge.first});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, X;
    cin >> N >> M >> X;
    vector<ll> T(M), u(M), v(M);
    rep(i, M) cin >> u[i] >> v[i] >> T[i];
    rep(i, M) u[i]--, v[i]--;
    vector<vector<pair<int, ll>>> G(N);
    rep(i, M) {
        G[u[i]].push_back({v[i], T[i]});
        G[v[i]].push_back({u[i], T[i]});
    }
    ll dmin = dijkstra(G, N, 0)[N - 1];
    ll ok = INF, ng = 0;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        vector<vector<pair<int, ll>>> G2(N);
        rep(i, M) {
            if (T[i] <= mid) {
                G2[u[i]].push_back({v[i], T[i]});
                G2[v[i]].push_back({u[i], T[i]});
            }
        }
        ll d = dijkstra(G2, N, 0)[N - 1];
        if (dmin * (X + 100) / 100 >= d)
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
