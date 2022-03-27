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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    V<int> X(N);
    rep(i, N) cin >> X[i];
    V<V<int>> G(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    V<V<int>> S(N);
    auto rec = [&](auto self, int cur, int par) -> int {
        V<int> ret = {X[cur]};
        for (auto &nx : G[cur]) {
            if (nx == par) continue;
            self(self, nx, cur);
            for (auto &si : S[nx]) ret.push_back(si);
        }
        sort(ret.rbegin(), ret.rend());
        rep(i, min(20, (int)ret.size())) S[cur].push_back(ret[i]);
        return 0;
    };
    rec(rec, 0, -1);
    while (Q--) {
        int V, K;
        cin >> V >> K;
        V--, K--;
        cout << S[V][K] << '\n';
    }
    return 0;
}

/**
 * 上位20個をもってDFSする
 */
