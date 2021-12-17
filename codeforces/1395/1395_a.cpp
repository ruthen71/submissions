#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void solve() {
    ll r, g, b, w;
    cin >> r >> g >> b >> w;
    ll ope = min({r, g, b});
    ope = min(ope, 2ll);
    int ok = 0;
    rep(i, ope + 1) {
        ll s = (r % 2) + (g % 2) + (b % 2) + (w % 2);
        if (s <= 1) ok = 1;
        r--, g--, b--, w += 3;
    }
    puts(ok ? "Yes" : "No");
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
