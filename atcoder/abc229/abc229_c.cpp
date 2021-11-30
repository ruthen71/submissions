#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    ll N, W;
    cin >> N >> W;
    vector<pair<ll, ll>> g(N);
    rep(i, N) cin >> g[i].first >> g[i].second;
    sort(ALL(g));
    reverse(ALL(g));
    ll ans = 0;
    rep(i, N) {
        if (W <= 0) break;
        ll c = min(W, g[i].second);
        ans += g[i].first * c;
        W -= c;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 大きいほうから貪欲
 */
