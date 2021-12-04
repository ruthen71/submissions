#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        ll ans = max({a * y, x * b, a * (b - 1 - y), (a - 1 - x) * b});
        cout << ans << endl;
    }
    return 0;
}
