#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void solve(string S) {
    int N = S.size();
    vector<vector<int>> dp(N, vector<int>(11, 0));
    dp[0][S[0] - '0'] = 1;
    rep(i, N - 1) {
        rep(j, 11) dp[i + 1][(10 * j + S[i + 1] - '0') % 11] += dp[i][j];
        if (S[i + 1] != '0') dp[i + 1][S[i + 1] - '0']++;
    }
    int ans = 0;
    rep(i, N) ans += dp[i][0];
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    while (cin >> S, S != "0") solve(S);
    return 0;
}

/**
 * 桁DP
 * Leading Zeros を許容しないので少し場合分けが必要
 */
