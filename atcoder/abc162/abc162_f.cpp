#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
const ll INF = 1ll << 60;
ll dp[200005][10][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    rep(i, N + 1) rep(j, 10) rep(k, 2) dp[i][j][k] = -INF;
    dp[0][5][0] = 0;
    rep(i, N) {
        rep(j, 10) {
            rep(k, 2) {
                if (dp[i][j][k] == -INF) continue;
                if (k == 0) {
                    // 使う
                    if (j - 1 >= 0) dp[i + 1][j - 1][1] = max(dp[i + 1][j - 1][1], dp[i][j][k] + A[i]);
                    // 使わない
                    if (j + 1 < 10) dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][k]);
                } else {
                    // 使わない
                    if (j + 1 < 10) dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][k]);
                }
            }
        }
    }
    if (N & 1) {
        cout << max(dp[N][1 + 5][0], dp[N][1 + 5][1]) << '\n';
    } else {
        cout << max(dp[N][0 + 5][0], dp[N][0 + 5][1]) << '\n';
    }
    return 0;
}

/**
 * 使わない個数-使う個数は、前から見ていくとそこまで大きくならない(具体的には-1から2まで)
 * なのでdp[i][j][k]=i番目まで見ており、使わない個数-使う個数=j, 直前の要素を使っているか?(k)
 * とすれば良い
 */
