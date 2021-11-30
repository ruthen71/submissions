#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

using mint = modint1000000007;

int main() {
    int N;
    cin >> N;
    string W;
    cin >> W;
    int len = W.size();
    vector<string> ws(N);
    vector<ll> wi(N);
    rep(i, N) cin >> ws[i] >> wi[i];
    vector<mint> dp(len + 1, 0);
    dp[0] = 1;
    rep(i, len) {
        rep(j, N) {
            if (i + ws[j].size() > len) continue;
            if (ws[j] == W.substr(i, ws[j].size())) dp[i + ws[j].size()] += dp[i] * wi[j];
        }
    }
    cout << dp[len].val() << '\n';
    return 0;
}

/**
 * dp[i]=i文字目までの意味の種類数として配るDP
 * 分割DP？みたいなことをやる(こんな用語はないかもしれない)
 */