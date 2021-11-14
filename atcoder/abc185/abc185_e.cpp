#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll INF = 1ll << 60;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
    rep(i, N) dp[i + 1][0] = i + 1;
    rep(j, M) dp[0][j + 1] = j + 1;
    rep(i, N) {
        rep(j, M) {
            if (A[i] == B[j]) {
                dp[i + 1][j + 1] = min(dp[i][j + 1] + 1, min(dp[i + 1][j] + 1, dp[i][j]));
            } else {
                dp[i + 1][j + 1] = min(dp[i][j + 1] + 1, min(dp[i + 1][j] + 1, dp[i][j] + 1));
            }
        }
    }
    ll ans = dp[N][M];
    cout << ans << endl;
    return 0;
}

/*
レーベンシュタイン距離
普通にやる
*/