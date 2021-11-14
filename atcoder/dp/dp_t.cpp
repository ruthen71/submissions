#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

using mint = modint1000000007;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<mint>> dp(N, vector<mint>(N, 0));
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        vector<mint> cum(i + 1, 0);
        for (int j = 0; j < i; j++) cum[j + 1] = cum[j] + dp[i - 1][j];
        if (S[i - 1] == '<')
            for (int j = 0; j <= i; j++) dp[i][j] = cum[j];
        else
            for (int j = 0; j <= i; j++) dp[i][j] = cum[i] - cum[j];
    }
    mint ans = 0;
    for (int j = 0; j < N; j++) ans += dp[N - 1][j];
    cout << ans.val() << endl;
    return 0;
}

/*
挿入DP
EDPC-T
https://www.youtube.com/watch?v=REjKdVm9WJc
わかりやすい
*/