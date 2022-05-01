#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T> using V = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    ll ans = 0;
    for (int d = 1; d <= N; d++) {
        ll c = N / d;
        ans += c * (c + 1) / 2 * d;
    }
    cout << ans << '\n';
    return 0;
}
