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
    int R, C, K;
    cin >> R >> C >> K;
    V<V<ll>> v(R, V<ll>(C, 0));
    rep(i, K) {
        int r, c, vv;
        cin >> r >> c >> vv;
        v[r - 1][c - 1] = vv;
    }
    V<V<V<ll>>> dp(R, V<V<ll>>(C, V<ll>(4, 0)));
    dp[0][0][1] = v[0][0];
    rep(i, R) {
        rep(j, C) {
            rep(k, 4) {
                if (i + 1 < R) {
                    // 拾わない
                    dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][k]);
                    // 拾う
                    dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][k] + v[i + 1][j]);
                }
                if (j + 1 < C) {
                    // 拾わない
                    dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
                    // 拾う
                    if (k + 1 < 4) dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k] + v[i][j + 1]);
                }
            }
        }
    }
    show(dp);
    cout << (*max_element(dp[R - 1][C - 1].begin(), dp[R - 1][C - 1].end())) << '\n';
    return 0;
}

/**
 * DP
 */