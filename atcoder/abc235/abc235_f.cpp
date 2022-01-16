#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

using mint = modint998244353;

const int B = 1 << 10;
mint dps[10005][2][B], dpc[10005][2][B];  // 総和と個数

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    int M;
    cin >> S >> M;
    vector<int> C(M);
    rep(i, M) cin >> C[i];
    int N = S.size();
    dpc[0][0][0] = 1;
    int bb = 0;
    for (int i = 1; i <= 9; i++) bb += 1 << i;
    rep(i, N) {
        rep(j, 2) {
            rep(b, B) {
                if (dpc[i][j][b] == 0 && dps[i][j][b] == 0) continue;
                if (b == 1) continue;
                int D = j ? 9 : S[i] - '0';
                for (int d = 0; d <= D; d++) {
                    int nxb = (b | (1 << d));
                    if (b == 0 && d == 0) nxb = 0;
                    dpc[i + 1][j | (d < S[i] - '0')][nxb] += dpc[i][j][b];
                    dps[i + 1][j | (d < S[i] - '0')][nxb] += dps[i][j][b] * 10 + d * dpc[i][j][b];
                }
            }
        }
    }
    int cb = 0;
    for (auto c : C) cb += (1 << c);
    mint ans = 0;
    rep(b, B) {
        if ((cb & b) == cb) {
            rep(j, 2) ans += dps[N][j][b];
        }
    }
    cout << ans.val() << '\n';
    return 0;
}

/**
 * 桁DP
 * dp[i][j][S]=i桁目まで見ており、ぴったりならj=0、小さいならj=1、Sは含まれる数の集合
 * leading zerosを許さないため、S={}から次の桁が0のときS={0}ではなくS={}のままにすることに注意
 * さらに、総和であり
 * dps[i + 1][j | (d < S[i] - '0')][nxb] += dps[i][j][b] * 10 + d * dpc[i][j][b];
 * のところで使う都合で個数も数える必要があることにも注意
 */
