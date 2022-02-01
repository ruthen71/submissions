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

ll x[205], y[205], r[205];

bool intersect(int i, int j) {
    ll d2 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    return d2 <= (r[i] + r[j]) * (r[i] + r[j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    UnionFind uf(N + 2);
    rep(i, N) cin >> x[i] >> y[i] >> r[i];
    rep(i, N) {
        rep(j, i) {
            if (intersect(i, j)) uf.merge(i, j);
        }
        if (x[i] - r[i] < 0) uf.merge(i, N);
        if (x[i] + r[i] > 200) uf.merge(i, N + 1);
        if (uf.same(N, N + 1)) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}

/**
 * 解説AC
 * そもそもロボットは直進じゃなくても良いです（誤読していた）
 * x=0とx=200の間に円のゴールテープを貼るイメージ
 * UnionFindを使う
 */
