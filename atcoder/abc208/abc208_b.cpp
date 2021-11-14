#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll P;
    cin >> P;
    ll m = 1;
    for (ll i = 2; i <= 10; i++) m *= i;
    ll ans = 0;
    for (ll i = 10; i >= 1; i--) {
        ans += P / m;
        P %= m;
        m /= i;
    }
    cout << ans << endl;
    return 0;
}
