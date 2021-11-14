#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll L;
    cin >> L;
    vector<ll> a(11);
    rep(i, 11) a[i] = L - 1 - i;
    vector<ll> b = {2, 3, 2, 2, 5, 2, 3, 7, 2, 2, 2, 3, 3, 2, 5, 11};
    for (auto bi : b) {
        rep(i, 11) {
            if (a[i] % bi == 0) {
                a[i] /= bi;
                break;
            }
        }
    }
    ll ans = 1;
    rep(i, 11) ans *= a[i];
    cout << ans << endl;
    return 0;
}
