#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
const ll INF = 1ll << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll S, T, D;
    cin >> S >> T >> D;
    vector<ll> w(D);
    rep(i, D) cin >> w[i];
    ll red = 0;
    rep(i, D) {
        red += w[i];
        if (S + red <= T) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    if (red >= 0) {
        cout << -1 << '\n';
        return 0;
    }
    ll R = S - T;
    red = -red;
    ll red2 = 0, ans = INF;
    rep(i, D) {
        red2 -= w[i];
        // R <= red * x + red2, minimize(x)
        // R-red2 <= red * x
        ll x = (R - red2 + red - 1) / red;
        ans = min(ans, D * x + i + 1);
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 1周で終わるか、終わらない場合は場合分けして頑張る
 */
