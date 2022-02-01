#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
mint dp[1005][11][11][11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    dp[0][10][10][10] = 1;
    rep(i, N) {
        rep(a1, 11) {
            rep(a2, 11) {
                rep(a3, 11) {
                    if (dp[i][a1][a2][a3] == 0) continue;
                    rep(m, M) {
                        if (m > a3) break;
                        int na1 = min(a1, m);
                        int na2 = (a1 < m) ? min(a2, m) : a2;
                        int na3 = (a2 < m) ? min(a3, m) : a3;
                        dp[i + 1][na1][na2][na3] += dp[i][a1][a2][a3];
                    }
                }
            }
        }
    }
    mint ans = 0;
    rep(a1, 10) rep(a2, 10) rep(a3, 10) ans += dp[N][a1][a2][a3];
    cout << ans.val() << '\n';
    return 0;
}

/**
 * 解説AC
 * 解説の1行目だけ見た
 * ある数列において、LISの長さが1,2,3のもののうち、辞書順最小のものをstringで持つ解法を実装していた
 * 例えば[3,4,1,5]なら、順に、1,34,345というように
 * 遷移を、LIS=1のやつは、今の要素と追加する要素の小さいほう
 * LIS=2のやつは、今の要素と、LIS=1の末尾に追加する要素をつけたものの小さいほう
 * LIS=3のやつは、今の要素と、LIS=2の末尾に追加する要素をつけたものの小さいほう
 * と考えると、末尾の要素だけで良いので状態数が削減できる…
 */