#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
const ll INF = 1ll << 60;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    s = "0" + s + "0";
    vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));
    dp[0][0] = b;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1' || s[i + 1] == '1') {
            dp[i][1] = min(dp[i - 1][1] + 2 * b + a, dp[i - 1][0] + 2 * b + 2 * a);
        } else {
            dp[i][1] = min(dp[i - 1][1] + 2 * b + a, dp[i - 1][0] + 2 * b + 2 * a);
            dp[i][0] = min(dp[i - 1][0] + b + a, dp[i - 1][1] + b + 2 * a);
        }
    }
    cout << dp[n][0] << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
