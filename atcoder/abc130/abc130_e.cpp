#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

using mint = modint1000000007;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(j, M) cin >> T[j];
    vector<vector<mint>> dp(N + 1, vector<mint>(M + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            // calc dp[i][j] (もらう)
            if (i) dp[i][j] += dp[i - 1][j];
            if (j) dp[i][j] += dp[i][j - 1];
            if (i && j) {
                dp[i][j] -= dp[i - 1][j - 1];
                if (S[i - 1] == T[j - 1]) dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[N][M].val() << '\n';
    return 0;
}

/**
 * DP
 * 動的計画法
 * dp
 * LCSっぽく考える
 * dp[i][j]=(S0...Si)と(T0...Tj)までを使って
 * 題意の列を作る場合の数
 * 更新は上を参照
 * イメージは二次元累積和
 */