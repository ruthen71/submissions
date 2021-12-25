#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll L, R;
    cin >> L >> R;
    ll ans = 2018;
    for (ll i = L; i <= min(R, L + 2019); i++) {
        for (ll j = i + 1; j <= min(R, L + 2019); j++) {
            ans = min(ans, i * j % 2019);
        }
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 区間[L, min(R, L+2019)]を全探索
 */
