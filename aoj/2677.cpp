#include <bits/stdc++.h>
using namespace std;
// clang-format off
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
template <class T> using V = vector<T>;
// clang-format on

struct lowest_common_ancestor {
    vector<vector<int>> G;
    vector<int> depth;
    vector<vector<int>> parent;
    int n, LOG;  // n = 頂点数, root = 根とする頂点番号, LOG = ダブリングする深さ
    lowest_common_ancestor(int n) : n(n), LOG(32 - __builtin_clz(n)), G(n) {}
    void add_edge(int u, int v) {
        // 無向辺{u, v}を加える
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void build(int root = 0) {
        depth.assign(n, 0);
        parent.assign(LOG, vector<int>(n, 0));
        dfs(root, -1, 0);
        for (int k = 0; k + 1 < LOG; k++) {
            for (int v = 0; v < n; v++) {
                if (parent[k][v] < 0)
                    parent[k + 1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }
    void dfs(int cur, int par, int d) {
        parent[0][cur] = par;
        depth[cur] = d;
        for (auto &nx : G[cur]) {
            if (nx != par) dfs(nx, cur, d + 1);
        }
    }
    int lca(int u, int v) {
        assert((int)depth.size() == n);
        if (depth[u] > depth[v]) swap(u, v);
        // depth[u] <= depth[v](vの方が深い)
        // 同じ深さまでvが登る
        for (int k = 0; k < LOG; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;
        for (int k = LOG - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

const int INF = 1 << 30;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    V<V<int>> G(n);
    lowest_common_ancestor lca(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        G[i].push_back(p);
        G[p].push_back(i);
        lca.add_edge(i, p);
    }
    lca.build();
    rep(i, n) sort(ALL(G[i]));
    queue<int> que;
    V<int> d(n, INF);
    d[0] = 0;
    ll ans = 0;
    que.push(0);
    int las = 0;
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        int lcav = lca.lca(las, v);
        ans += d[las] - d[lcav];
        ans += d[v] - d[lcav];
        for (auto &nx : G[v]) {
            if (d[nx] == INF) {
                d[nx] = d[v] + 1;
                que.push(nx);
            }
        }
        las = v;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * LCAやるだけ
 */