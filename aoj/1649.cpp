#include <bits/stdc++.h>
using namespace std;

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

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void solve(int H, int W) {
    UnionFind uf(H + W);
    vector<vector<int>> u(H), v(W);
    rep(i, H + W - 1) {
        int a, b, n;
        cin >> a >> b >> n;
        a--, b--;
        u[a].push_back(b);
        v[b].push_back(a);
    }
    rep(i, H) { rep(k, u[i].size()) uf.merge(u[i][0], u[i][k]); }
    rep(j, W) rep(k, v[j].size()) uf.merge(W + v[j][0], W + v[j][k]);
    if (uf.size(0) == W && uf.size(W) == H)
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    while (cin >> H >> W, H | W) solve(H, W);
    return 0;
}

/**
 * ICPC国内予選ではWAを出したが今回は一発AC
 */
