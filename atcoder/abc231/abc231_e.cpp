#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

const ll INF = 1ll << 60;

int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    reverse(ALL(A));
    vector<ll> B(N);
    rep(i, N) {
        B[i] = X / A[i];
        X %= A[i];
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(2, INF));
    dp[0][0] = 0;
    rep(i, N) {
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + B[i]);
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + B[i] + 1);
        if (i) dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + A[i - 1] / A[i] - B[i]);
        if (i) dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + A[i - 1] / A[i] - B[i] - 1);
    }
    cout << dp[N][0] << '\n';
    return 0;
}

/**
 * 硬貨の問題(おつりを含めた枚数最小化)
 * ABC155 で既出
 * 各硬貨はぴったりか、高々1枚余計に払う場合だけ考えればOK
 * (2枚以上払ってもおつりとしてそのまま帰ってくる)
 */
