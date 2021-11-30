#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

ll f(ll x) {
    if (x <= 1) return 0ll;
    // [0, x)
    ll p10 = 1, ans = 0;
    for (int i = 0; i <= 15; i++) {
        p10 *= 10;
        ans += (x / p10) * 45 * (p10 / 10);
        ll r = x % p10;
        for (int d = 0; d <= 9; d++) {
            ans += d * min(r, p10 / 10);
            r -= min(r, p10 / 10);
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll ans = f(b + 1) - f(a);
        cout << ans << '\n';
    }
    return 0;
}

/**
 * [0,x)の整数の桁和を求めれば良い
 * 桁DPでも解けるが、自分は気合で実装した
 */