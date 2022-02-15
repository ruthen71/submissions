#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, H, W;
    cin >> N >> H >> W;
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    UnionFind uf(N);
    rep(j, N) {
        rep(i, j) {
            if (x[i] == x[j] || y[i] == y[j]) {
                uf.merge(i, j);
            }
        }
    }
    vector<int> x0(N, 0), xH(N, 0), y0(N, 0), yW(N, 0);
    rep(i, N) {
        if (x[i] == 1) x0[uf.leader(i)] = 1;
        if (x[i] == H) xH[uf.leader(i)] = 1;
        if (y[i] == 1) y0[uf.leader(i)] = 1;
        if (y[i] == W) yW[uf.leader(i)] = 1;
    }
    int csize = 0;
    rep(i, N) {
        if (i == uf.leader(i)) csize++;
    }
    int ans = N - csize;
    if (csize == 1) {
        cout << ans << '\n';
        return 0;
    }
    int sx0 = 0, sxH = 0, sy0 = 0, syW = 0;
    rep(i, N) {
        sx0 += x0[i];
        sxH += xH[i];
        sy0 += y0[i];
        syW += yW[i];
    }
    ans += csize - 1;
    ans += csize - max({sx0, sxH, sy0, syW});
    cout << ans << '\n';
    return 0;
}

/**
 * 最小全域木風？
 * まずコスト1の辺は全てつなげる
 * 壁を使う必要があるものについては、どこかの壁に寄せる
 */
