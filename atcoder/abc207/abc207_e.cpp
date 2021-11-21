#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

using mint = modint1000000007;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> cum(N + 1, 0);
    rep(i, N) cum[i + 1] = cum[i] + A[i];
    vector<vector<mint>> G(N + 1, vector<mint>(N, 0));
    vector<vector<mint>> dp(N + 1, vector<mint>(N + 1, 0));
    dp[0][0] = 1;
    G[1][0] = 1;
    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] += G[j][cum[i] % j];
            // for (int k = 0; k < i; k++) if ((cum[i] - cum[k]) % j == 0) dp[i][j] += dp[k][j - 1];
        }
        for (int j = 1; j < N; j++) G[j + 1][cum[i] % (j + 1)] += dp[i][j];
    }
    mint ans = 0;
    rep(i, N + 1) ans += dp[N][i];
    cout << ans.val() << endl;
    return 0;
}

/*
コンテスト終了後AC
もらうDP
貰うDP
データ構造で高速化
貰える条件を累積和を使って書きなおすと
(cum[i] - cum[k]) % j == 0
これをcum[i]%j==cum[k]%jと言い換えると、iについて見ているときにk<i(それより小さい)
値に対してcum[k]%jの値ごとに和をまとめておけばよい
*/
