#include <bits/stdc++.h>
using namespace std;

#include <atcoder/dsu>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> u(M + Q), v(M + Q), w(M + Q);
    rep(i, M + Q) cin >> u[i] >> v[i] >> w[i];
    rep(i, M + Q) u[i]--, v[i]--;
    vector<pair<int, int>> es(M + Q);
    rep(i, M + Q) es[i] = {w[i], i};
    sort(ALL(es));
    dsu uf(N);
    vector<int> ans(Q);
    for (auto &e : es) {
        if (e.second >= M) {
            // クエリの辺
            if (!uf.same(u[e.second], v[e.second])) {
                ans[e.second - M] = 1;
            } else {
                ans[e.second - M] = 0;
            }
        } else {
            // もともとある辺
            if (!uf.same(u[e.second], v[e.second])) {
                uf.merge(u[e.second], v[e.second]);
            }
        }
    }
    rep(i, Q) cout << (ans[i] ? "Yes" : "No") << '\n';
    return 0;
}

/**
 * Kruskal法の要領でつなげていくことを考え、クエリの辺が来たらそれを繋ぐ必要があるか考える
 * Link/Cut Tree を使うとグラフGが前のクエリの辺に依存する場合も解けるらしい
 */
