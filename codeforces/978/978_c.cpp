#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> b(m);
    rep(i, m) cin >> b[i];
    vector<ll> cum(n + 1, 0);
    rep(i, n) cum[i + 1] = cum[i] + a[i];
    rep(i, m) {
        int r = lower_bound(ALL(cum), b[i]) - cum.begin();
        cout << r << " " << b[i] - cum[r - 1] << '\n';
    }
    return 0;
}
