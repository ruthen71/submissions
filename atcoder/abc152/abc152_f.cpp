#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

vector<int> dfs(vector<vector<int>> &G, map<pair<int, int>, int> &eid, int cur, int par, int pur) {
    if (cur == pur) {
        vector<int> res = {eid[{cur, par}]};
        return res;
    }
    for (auto &nx : G[cur]) {
        if (nx == par) continue;
        auto res = dfs(G, eid, nx, cur, pur);
        if (res.size() == 0) continue;
        if (par != -1) res.push_back(eid[{cur, par}]);
        return res;
    }
    return vector<int>();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    map<pair<int, int>, int> eid;
    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        eid[{u, v}] = i;
        eid[{v, u}] = i;
    }
    int M;
    cin >> M;
    vector<ll> cb(M, 0);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        vector<int> es = dfs(G, eid, u, -1, v);
        for (auto &ei : es) cb[i] |= (1ll << ei);
    }
    ll ans = 0;
    vector<ll> p2(N, 1);
    rep(i, N - 1) p2[i + 1] = 2 * p2[i];
    for (int b = 1; b < (1 << M); b++) {
        ll bc = 0;
        rep(i, M) if (b >> i & 1) bc |= cb[i];
        int cnt = __builtin_popcountll(bc);
        ans += p2[N - 1 - cnt] * ((__builtin_popcount(b) % 2 == 1) ? (1) : -1);
    }
    cout << p2[N - 1] - ans << '\n';
    return 0;
}

/**
 * 包除原理
 * ダメなものの個数をansで数え上げる
 * 少なくとも1つの条件に付いて、u->vへのパス(木なので一意)に含まれる辺が全て白
 * よってこれを包除原理で求める
 */
