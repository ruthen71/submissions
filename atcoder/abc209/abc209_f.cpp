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
    vector<int> H(N);
    rep(i, N) cin >> H[i];
    vector<vector<mint>> dp(N, vector<mint>(N, 0));
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        vector<mint> cum(i + 1, 0);
        rep(j, i) cum[j + 1] = (cum[j] + dp[i - 1][j]);
        if (H[i - 1] < H[i]) {
            // H[i]を先に取り除く
            for (int j = 0; j <= i; j++) {
                // for (int k = j; k < i; k++) dp[i][j] += dp[i - 1][k];
                dp[i][j] = cum[i] - cum[j];
            }
        }
        if (H[i - 1] > H[i]) {
            // H[i-1]を先に取り除く
            for (int j = 0; j <= i; j++) {
                // for (int k = 0; k < j; k++) dp[i][j] += dp[i - 1][k];
                dp[i][j] = cum[j];
            }
        }
        if (H[i - 1] == H[i]) {
            // どちらを先に取り除いてもOK
            for (int j = 0; j <= i; j++) {
                // for (int k = 0; k < i; k++) dp[i][j] += dp[i - 1][k];
                dp[i][j] = cum[i];
            }
        }
    }
    mint ans = 0;
    rep(j, N) ans += dp[N - 1][j];
    cout << ans.val() << endl;
    return 0;
}

/*
順列
DP
挿入DP
隣接2つの要素のどっちを先に入れると答えのコストが小さくなるかはわかるので、順序関係が決まり、
EDPC-Tに帰着する
もらうDPで実装するとわかりやすい
*/