#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

using mint = modint998244353;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> cum(N + 1, 0);
    rep(i, N) cum[i + 1] = cum[i] + A[i];
    vector<mint> dp(N + 1, 0);
    dp[0] = 1;
    map<ll, int> Rid;
    vector<mint> dpcum(N + 2, 0);  // dp[0,i)の和
    dpcum[1] = 1;
    for (int i = 1; i <= N; i++) {
        int j = Rid[cum[i]];
        // for (int k = j; k < i; k++) dp[i] += dp[k];
        dp[i] = dpcum[i] - dpcum[j];
        dpcum[i + 1] = dpcum[i] + dp[i];
        Rid[cum[i]] = i;
    }
    mint ans = 0;
    for (int i = 1; i <= N; i++) {
        if (cum[N] == cum[i]) ans += dp[i];
    }
    cout << ans.val() << '\n';
    return 0;
}

/**
 * 解説AC
 * 部分列DP
 * 作れる数列と操作列を一対一対応させる(典型らしい)
 */
