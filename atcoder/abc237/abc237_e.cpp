#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
const ll INF = 1ll << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<ll> H(N);
    rep(i, N) cin >> H[i];
    vector<vector<pair<int, ll>>> G(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (H[u] > H[v]) swap(u, v);
        // H[u] <= H[v]
        G[u].push_back({v, H[v] - H[u]});
        G[v].push_back({u, 0});
    }
    vector<ll> dist(N, INF);
    dist[0] = -H[0];
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.push({-H[0], 0});
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        if (dist[p.second] < p.first) continue;
        for (auto &es : G[p.second]) {
            if (dist[es.first] > dist[p.second] + es.second) {
                dist[es.first] = dist[p.second] + es.second;
                que.push({dist[es.first], es.first});
            }
        }
    }
    ll ans = 0;
    rep(i, N) ans = max(ans, -(dist[i] + H[i]));
    cout << ans << '\n';
    return 0;
}

/**
 * 嘘解法AC
 * どうやら負辺を許してダイクストラしても通るらしい…
 * 自分はコンテスト中に現在地が高いものからやるという小細工を入れたが、それでもafter contestで落ちた
 * ポテンシャルを考える
 * 負辺あり最小費用流などで使われるテクニックらしい
 */
