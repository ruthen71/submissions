#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T> using V = vector<T>;

#include <atcoder/scc>
using namespace atcoder;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    V<int> u(M), v(M);
    V<V<int>> G(N);
    scc_graph G2(N);
    rep(i, M) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        G[u[i]].push_back(v[i]);
        G2.add_edge(u[i], v[i]);
    }
    V<V<int>> sl = G2.scc();
    int L = sl.size(), ans = 0;
    V<int> ok(L, 0), id(N, -1);
    rep(i, L) {
        for (auto &j : sl[i]) {
            id[j] = i;
        }
    }
    for (int i = L - 1; i >= 0; i--) {
        if (sl[i].size() >= 2) {
            ok[i] = 1;
        } else {
            for (auto &nx : G[sl[i][0]]) {
                if (ok[id[nx]] == 1) {
                    ok[i] = 1;
                    break;
                }
            }
        }
        if (ok[i]) ans += sl[i].size();
    }
    cout << ans << '\n';
    return 0;
}