#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

using mint = modint1000000007;

int main() {
    ll N, K;
    cin >> N >> K;
    ll sqN = sqrt(N);
    assert(sqN * sqN <= N && (sqN + 1) * (sqN + 1) > N);
    vector<vector<mint>> dp1(K + 1, vector<mint>(sqN + 1, 0)), dp2(K + 1, vector<mint>(sqN + 1, 0));
    dp1[0][1] = 1;
    rep(k, K) {
        // calc dp1
        mint s = 0;
        for (int i = 1; i <= sqN; i++) s += dp1[k][i];
        for (int i = sqN; i > 0; i--) {
            s += dp2[k][i];
            dp1[k + 1][i] += s;
        }
        // calc dp2
        mint s2 = 0;
        for (int i = 1; i <= sqN; i++) s2 += dp1[k][i];
        ll lst = sqN;
        for (int i = sqN; i > 0; i--) {
            dp2[k + 1][i] += (N / i - lst) * s2;
            lst = N / i;
            s2 -= dp1[k][i];
        }
    }
    mint ans = 0;
    for (int i = 1; i <= sqN; i++) ans += dp1[K][i] + dp2[K][i];
    cout << ans.val() << '\n';
    return 0;
}

/**
 * dpする
 * 動的計画法
 * dp1[i][j]=i番目の要素まで見ており、末尾がjであるもの(1<=j<=sqrt(N))
 * dp2[i][j]=i番目の要素まで見ており、末尾の要素とかけられる最大値がj(jの範囲は同様)
 * dp1->dp1は普通に
 * dp2->dp1はそんなに難しくない
 * dp2->dp2はない
 * dp1->dp2は難しめ、dp2の持ち方的にはかけられる値を目安にしているが
 * 実際には末尾にsqrt(N)以上の値が入る場合を複数まとめて更新している
 * と考えると良い
 */
