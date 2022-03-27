#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) begin(x), end(x)
template <class T> using V = vector<T>;

#include <atcoder/maxflow>
using namespace atcoder;

const ll INF = 1LL << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, M;
    cin >> N >> M;
    V<ll> u(M), v(M), c(N);
    rep(i, M) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
    }
    rep(i, N) cin >> c[i];
    mf_graph<ll> G(2 * N);
    rep(i, N) G.add_edge(2 * i, 2 * i + 1, c[i]);
    rep(i, M) {
        // u[i]->v[i]
        G.add_edge(2 * u[i] + 1, 2 * v[i], INF);
        // v[i]->u[i]
        G.add_edge(2 * v[i] + 1, 2 * u[i], INF);
    }
    ll ans = G.flow(1, 2 * (N - 1));
    cout << ans << '\n';
    auto mc = G.min_cut(1);
    V<int> ansv;
    for (int i = 1; i < N - 1; i++) {
        if (mc[2 * i] != mc[2 * i + 1]) {
            ansv.push_back(i);
        }
    }
    cout << ansv.size() << '\n';
    assert(ansv.size() > 0);
    rep(i, ansv.size()) cout << ansv[i] + 1 << (i == ansv.size() - 1 ? '\n' : ' ');
    return 0;
}

/**
 * 最大流
 * 最小カット
 * 頂点に重みがあるときは頂点を倍にする
 * 容量INFの辺を貼る
 */
