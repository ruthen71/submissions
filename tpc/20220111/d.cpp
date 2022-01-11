#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const ll INF = 1ll << 60;

void solve() {
    int N, M, T;
    cin >> N >> M >> T;
    int S, u, v;
    cin >> S >> u >> v;
    S--, u--, v--;
    vector<vector<pair<int, ll>>> G(N);
    rep(i, M) {
        int a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        G[a].push_back({b, d});
        G[b].push_back({a, d});
    }
    vector<int> x(T);
    rep(i, T) cin >> x[i];
    rep(i, T) x[i]--;
    vector<ll> dist(N, INF);
    vector<int> used(N, 0);
    dist[S] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, S});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (dist[p.second] < p.first) continue;
        for (auto &pre : G[p.second]) {
            if (dist[pre.first] + pre.second == dist[p.second]) {
                if (used[pre.first]) used[p.second] = 1;
                if (pre.first == u && p.second == v) used[p.second] = 1;
                if (pre.first == v && p.second == u) used[p.second] = 1;
            }
        }
        for (auto nx : G[p.second]) {
            if (dist[nx.first] > dist[p.second] + nx.second) {
                dist[nx.first] = dist[p.second] + nx.second;
                pq.push({dist[nx.first], nx.first});
            }
        }
    }
    vector<int> ans;
    for (auto xx : x) {
        if (used[xx]) ans.push_back(xx);
    }
    assert(ans.size() != 0);
    sort(ALL(ans));
    rep(i, ans.size()) {
        if (i == 0)
            cout << ans[i] + 1;
        else
            cout << " " << ans[i] + 1;
    }
    cout << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}

/**
 * sからt個のxのいずれかに最短ルートで行くときに
 * 辺g-hを通る可能性のあるものを列挙せよ
 * 最短路が複数あるときを考えると、Dijkstra法で来たところをメモするのではダメ
 * (最短経路を1つしか求められない)
 * ある頂点から行けるところを見る(for(auto nx:G[p.second]))とき
 * その頂点の最短距離は確定していることを使う
 * よって、その頂点が来た可能性のある点の中に、g-hパスを通った点がある
 * あるいは、頂点と来た可能性のある点がg,h(順不同)だったときに(そのときのみ)答えになる
 * よってfor(auto nx:G[p.second])の前にfor (auto &pre : G[p.second])として処理してやる
 * O(MlogN+N)
 */
