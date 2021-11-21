#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

struct UnionFind {
    vector<int> parents;

    UnionFind() {}
    UnionFind(int n) : parents(n, -1) {}

    int leader(int x) {
        if (parents[x] < 0)
            return x;
        else
            return parents[x] = leader(parents[x]);
    }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        if (parents[x] > parents[y]) swap(x, y);
        parents[x] += parents[y];
        parents[y] = x;
        return true;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    int size(int x) { return -parents[leader(x)]; }
    void init(int n) { parents.assign(n, -1); }  // reset
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    UnionFind uf(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        uf.merge(u, v);
    }
    vector<int> en(n, 0), ok(n, 1);
    rep(i, n) {
        en[uf.leader(i)] += g[i].size();
        if (g[i].size() != 2) ok[uf.leader(i)] = 0;
    }
    int ans = 0;
    rep(i, n) {
        if (uf.leader(i) != i) continue;
        if (en[i] / 2 != uf.size(i)) continue;
        if (ok[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}

/*
Unionfindでサイクル判定
連結成分に含まれる辺の本数と連結成分の個数比較
*/