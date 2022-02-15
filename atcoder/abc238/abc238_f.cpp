#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

mint dp[305][305][305];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> P(N), Q(N);
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];
    rep(i, N) P[i]--, Q[i]--;
    vector<int> R(N, -1);
    rep(i, N) R[P[i]] = Q[i];
    dp[0][0][N] = 1;
    rep(i, N) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= N; k++) {
                if (dp[i][j][k] == 0) continue;
                // choose
                if (k > R[i]) dp[i + 1][j + 1][k] += dp[i][j][k];
                // don't choose
                dp[i + 1][j][min(k, R[i])] += dp[i][j][k];
            }
        }
    }
    mint ans = 0;
    rep(k, N + 1) ans += dp[N][K][k];
    cout << ans.val() << '\n';
    return 0;
}

/**
 * とりあえずPの順位が良い順に並べる
 * ナップサック的に要素を追加するかしないか選ぶときに、「それまでに選ばれなかったもののうちの最も良い順位」
 * より小さければ追加できる
 * 後に選ぶ要素は、Pの順位が悪いので、それらのせいで選べなくなるということがない
 *
 */
