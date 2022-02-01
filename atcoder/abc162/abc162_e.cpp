#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, K;
    cin >> N >> K;
    mint ans = 0;
    vector<mint> cnt(K + 1, 0);
    for (ll m = K; m > 0; m--) {
        // gcd(A[0],...,A[N-1])=mとなる数列の個数xを求める
        mint c = K / m;  // 1~Kに含まれるmの倍数
        mint x = c.pow(N);
        for (ll i = 2 * m; i <= K; i += m) x -= cnt[i];
        cnt[m] = x;
        ans += x * m;
    }
    cout << ans.val() << '\n';
    return 0;
}
/**
 * 約数包除
 * 包除原理
 */
