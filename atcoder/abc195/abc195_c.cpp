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
    ll ans = 0, cur = 1000;
    while (N - cur + 1 >= 0) {
        ans += max(N - cur + 1, 0LL);
        cur *= 1000;
    }
    cout << ans << '\n';
    return 0;
}