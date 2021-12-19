#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int INF = 1 << 30;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    rep(i, H) cin >> C[i];
    vector<vector<int>> dp(H, vector<int>(W, -INF));
    dp[0][0] = 1;
    rep(i, H) {
        rep(j, W) {
            if (C[i][j] == '#') continue;
            if (i && C[i - 1][j] == '.') dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
            if (j && C[i][j - 1] == '.') dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    int ans = 0;
    rep(i, H) rep(j, W) ans = max(ans, dp[i][j]);
    cout << ans << '\n';
    return 0;
}
/**
 * dp
 */