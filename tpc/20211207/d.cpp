#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

void solve() {
    int h, w;
    cin >> w >> h;
    vector<string> g(h);
    rep(i, h) cin >> g[i];
    string cur = "";
    rep(i, w) cur += ' ';
    ll ans = 0;
    rep(i, h) {
        int ok = 0;
        rep(j, w) {
            if (cur.substr(j) == g[i].substr(0, w - j)) {
                ok = 1;
                ans += j;
                cur = g[i];
                break;
            }
        }
        if (ok) continue;
        ans += w;
        cur = g[i];
    }
    cout << ans << '\n';
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
