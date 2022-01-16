#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int M = 1000;

void solve(int N) {
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    vector<vector<int>> dp(M, vector<int>(M, 0));
    dp[0][0] = 1;
    int s = 0;
    rep(t, N) {
        for (int i = M - 1; i >= 0; i--) {
            for (int j = M - 1; j >= 0; j--) {
                if (dp[i][j]) {
                    if (i + a[t] < M) dp[i + a[t]][j] = 1;
                    if (j + a[t] < M) dp[i][j + a[t]] = 1;
                }
            }
        }
        s += a[t];
    }
    int ans = 0;
    rep(i, M) rep(j, M) {
        if (dp[i][j]) {
            ans = max(ans, min({i, j, s - i - j}));
        }
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while (cin >> N, N) solve(N);
    return 0;
}

/**
 * 和を3分割するdp
 * ICPC国内予選で解けなかった因縁のある問題
 * 今見てもやはり言い換えがかなり難しい気がする
 */
