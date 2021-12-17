#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ll n, d, m;
    cin >> n >> d >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(ALL(a));
    reverse(ALL(a));
    vector<ll> a1, a2;
    rep(i, n) {
        if (a[i] <= m)
            a1.push_back(a[i]);
        else
            a2.push_back(a[i]);
    }
    ll n1 = a1.size(), n2 = a2.size();
    if (n1 == n) {
        ll ans = 0;
        rep(i, n) ans += a[i];
        cout << ans << '\n';
        return 0;
    }
    ll c = min(n2, (n + d) / (d + 1));
    ll ans = 0;
    vector<ll> cum1(n1 + 1, 0), cum2(n2 + 1, 0);
    rep(i, n1) cum1[i + 1] = cum1[i] + a1[i];
    rep(i, n2) cum2[i + 1] = cum2[i] + a2[i];
    for (int k = 0; k <= c; k++) {
        ll unused = max((k - 1) * d, 0ll);
        ll cur = cum2[k];
        unused -= (n2 - k);
        ll use = n1 - unused;
        use = max(0ll, use);
        use = min(n1, use);
        cur += cum1[use];
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}

/**
 * mより大きい値を使う個数を全探索する
 */
