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
    ll X, K, D;
    cin >> X >> K >> D;
    X = abs(X);
    __int128_t X2 = X, K2 = K, D2 = D;
    if (X2 >= K2 * D2) {
        cout << X - K * D << '\n';
    } else {
        ll X3 = X % D;
        ll c = (X - X3) / D;
        if (c % 2 == K % 2) {
            cout << X3 << '\n';
        } else {
            cout << abs(X3 - D) << '\n';
        }
    }
    return 0;
}

/**
 * __int128
 * https://kenkoooo.hatenablog.com/entry/2016/11/30/163533
 */