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
    int N, T;
    cin >> N >> T;
    V<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    V<V<ll>> dp0(N + 1, V<ll>(T + 1, 0)), dp1(N + 1, V<ll>(T + 1, 0));
    rep(i, N) {
        rep(j, T + 1) {
            dp0[i + 1][j] = max(dp0[i + 1][j], dp0[i][j]);
            if (j + A[i] <= T) dp0[i + 1][j + A[i]] = max(dp0[i + 1][j + A[i]], dp0[i][j] + B[i]);
        }
    }
    for (int i = N; i > 0; i--) {
        rep(j, T + 1) {
            dp1[i - 1][j] = max(dp1[i - 1][j], dp1[i][j]);
            if (j + A[i - 1] <= T) dp1[i - 1][j + A[i - 1]] = max(dp1[i - 1][j + A[i - 1]], dp1[i][j] + B[i - 1]);
        }
    }
    ll ans = 0;
    rep(i, N) rep(j, T) ans = max(ans, dp0[i][j] + dp1[i + 1][T - 1 - j] + B[i]);
    cout << ans << '\n';
    return 0;
}
