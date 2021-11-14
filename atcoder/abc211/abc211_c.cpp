#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll mod = 1000000007;

int c[1000];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string t = "chokudai";
    rep(i, 8) c[t[i]] = i + 1;
    vector<vector<ll>> dp(n + 1, vector<ll>(9, 0));
    dp[0][0] = 1;
    rep(i, n) {
        rep(j, 9) dp[i + 1][j] = dp[i][j];
        if (c[s[i]] != 0) {
            rep(j, 9) {
                if (c[s[i]] == j) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[n][8] << endl;
    return 0;
}
