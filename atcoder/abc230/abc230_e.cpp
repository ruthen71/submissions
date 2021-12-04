#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ll N;
    cin >> N;
    ll last = 0;
    ll ans = 0;
    for (ll i = 1; i * i <= N; i++) {
        ans += N / i;
        last = i;
    }
    for (ll i = last; i >= 1; i--) {
        ans += i * (N / i - last);
        last = N / i;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 平方分割する
 *
 */