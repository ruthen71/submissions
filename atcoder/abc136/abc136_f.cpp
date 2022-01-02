#include <bits/stdc++.h>
using namespace std;

#include <atcoder/fenwicktree>
#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

using mint = modint998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    vector<int> zx = x, zy = y;
    sort(ALL(zx));
    sort(ALL(zy));
    zx.erase(unique(ALL(zx)), zx.end());
    zy.erase(unique(ALL(zy)), zy.end());
    rep(i, N) x[i] = lower_bound(ALL(zx), x[i]) - zx.begin();
    rep(i, N) y[i] = lower_bound(ALL(zy), y[i]) - zy.begin();
    vector<int> G(N);
    rep(i, N) G[x[i]] = y[i];
    vector<vector<int>> P(N, vector<int>(4, 0));
    fenwick_tree<int> fw1(N), fw2(N);
    rep(i, N) {
        P[i][0] = fw1.sum(0, G[i]);
        P[i][1] = fw1.sum(G[i], N);
        fw1.add(G[i], 1);
    }
    for (int i = N - 1; i >= 0; i--) {
        P[i][2] = fw2.sum(0, G[i]);
        P[i][3] = fw2.sum(G[i], N);
        fw2.add(G[i], 1);
    }
    mint ans = 0;
    vector<mint> p2(N + 1, 1);
    rep(i, N) p2[i + 1] = p2[i] * 2;
    rep(i, N) {
        // その点はTに含まれないが、周りの点の影響でf(T)にカウントされる
        ans += (p2[P[i][1]] - 1) * (p2[P[i][2]] - 1) * (p2[P[i][0] + P[i][3]]);
        ans += (p2[P[i][0]] - 1) * (p2[P[i][3]] - 1) * (p2[P[i][1] + P[i][2]]);
        // 重複分を引く
        ans -= (p2[P[i][0]] - 1) * (p2[P[i][1]] - 1) * (p2[P[i][2]] - 1) * (p2[P[i][3]] - 1);
        // その点がTに含まれる
        ans += p2[N - 1];
    }
    cout << ans.val() << '\n';
    return 0;
}

/**
 * 幾何
 * 各点が含まれるようなTが何通りあるか考えるという典型考察をする
 * 平面走査+BIT
 * fenwick tree
 * 寄与を考える
 */
