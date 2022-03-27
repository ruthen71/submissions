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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, K;
    cin >> N >> K;
    V<int> P(N);
    rep(i, N) {
        cin >> P[i];
        P[i]--;
    }
    V<ll> C(N);
    rep(i, N) cin >> C[i];

    int LOG = 0;
    while ((1 << LOG) <= K) LOG++;
    show(LOG);
    const ll INF = 1LL << 60;
    V<V<int>> db1(LOG, V<int>(N));
    V<V<ll>> db2(LOG, V<ll>(N)), db3(LOG, V<ll>(N, -INF));
    rep(i, N) {
        db1[0][i] = P[i];
        db2[0][i] = C[P[i]];
        db3[0][i] = C[P[i]];
    }
    rep(k, LOG - 1) {
        rep(i, N) {
            db1[k + 1][i] = db1[k][db1[k][i]];
            db2[k + 1][i] = db2[k][i] + db2[k][db1[k][i]];
            db3[k + 1][i] = max(db3[k][i], db2[k][i] + db3[k][db1[k][i]]);
        }
    }
    ll ans = -INF;
    rep(i, N) {
        ll s = 0;
        int c = i;
        for (int k = LOG - 1; k >= 0; k--) {
            if (K >> k & 1) {
                ans = max(ans, s + db3[k][c]);
                s += db2[k][c];
                c = db1[k][c];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

/**
 * ダブリング
 */