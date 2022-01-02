#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

using mint = modint1000000007;

mint dp[100005][13];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    int N = S.size();
    dp[0][0] = 1;  // dp[i][k]=i桁目まで, mod13でk
    rep(i, N) {
        if (S[i] == '?') {
            rep(k, 13) {
                rep(d, 10) { dp[i + 1][(10 * k + d) % 13] += dp[i][k]; }
            }
        } else {
            rep(k, 13) { dp[i + 1][(10 * k + (S[i] - '0')) % 13] += dp[i][k]; }
        }
    }
    mint ans = dp[N][5];
    cout << ans.val() << '\n';
    return 0;
}

/**
 * digit DP
 * 桁dp
 * 桁DPやるだけ
 * 未満/ぴったりフラグがいらないので(S以下の個数、ではないため)、かなり楽
 */
