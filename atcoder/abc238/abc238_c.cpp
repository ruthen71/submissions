#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    mint mN = N, b = 0;
    mint ans = mN * (mN + 1) / 2;
    ll a = 9;
    while (N > 0) {
        ans -= b * min(N, a);
        N -= a;
        a = a * 10;
        b = 10 * b + 9;
    }
    cout << ans.val() << '\n';
    return 0;
}
/**
 * 桁数ごとに考える
 * 1+...+Nに比べてどのくらい引かれているか考える
 */
