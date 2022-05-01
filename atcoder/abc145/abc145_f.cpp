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
    int N, K;
    cin >> N >> K;
    V<ll> H(N);
    rep(i, N) cin >> H[i];
    V<ll> I = H;
    I.push_back(0);
    sort(I.begin(), I.end());
    I.erase(unique(I.begin(), I.end()), I.end());
    rep(i, N) H[i] = lower_bound(I.begin(), I.end(), H[i]) - I.begin();
    int M = I.size();
    const ll INF = 1LL << 60;
    // dp[i][k][j] = i番目の要素まで,塗り替え可能な要素数が残りk個,末尾の要素がI[j]
    V<V<V<ll>>> dp(N + 1, V<V<ll>>(K + 1, V<ll>(M, INF)));
    dp[0][K][0] = 0;
    for (int i = 1; i <= N; i++) {
        rep(k, K + 1) {
            // 変更しない
            rep(j, M) dp[i][k][H[i - 1]] = min(dp[i][k][H[i - 1]], dp[i - 1][k][j] + max(0LL, I[H[i - 1]] - I[j]));
            // 変更する
            //  if (k > 0) rep(l, M) rep(j, M) dp[i][k - 1][l] = min(dp[i][k - 1][l], dp[i - 1][k][j] + max(0LL, I[l] - I[j]));
            if (k > 0) {
                // l <= j と l > j に分ける
                // l <= j
                // max(0LL, I[l] - I[j]) = 0
                ll c1 = INF;
                for (int l = M - 1; l >= 0; l--) {
                    c1 = min(c1, dp[i - 1][k][l]);
                    dp[i][k - 1][l] = min(dp[i][k - 1][l], c1);
                }
                // l > j
                // dp[i - 1][k][j] + max(0LL, I[l] - I[j]) = (dp[i - 1][k][j] - I[j]) + I[l]
                ll c2 = dp[i - 1][k][0] - I[0];
                for (int l = 1; l < M; l++) {
                    c2 = min(c2, dp[i - 1][k][l] - I[l]);
                    dp[i][k - 1][l] = min(dp[i][k - 1][l], c2 + I[l]);
                }
            }
        }
    }
    ll ans = INF;
    rep(k, K + 1) rep(j, M) ans = min(ans, dp[N][k][j]);
    cout << ans << '\n';
    return 0;
}
