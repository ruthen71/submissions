#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

ll INF = 1ll << 60;

int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll c = 0, ub = 0, lb = 0;
    rep(i, n) {
        c += a[i];
        ub = max(ub, c);
        lb = min(lb, c);
    }
    if (ub - lb > w) {
        cout << 0 << '\n';
    } else {
        cout << w - (ub - lb) + 1 << '\n';
    }
    return 0;
}
