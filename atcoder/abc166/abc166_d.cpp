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
    ll X;
    cin >> X;
    auto f = [](ll x) -> ll { return x * x * x * x * x; };
    for (ll a = 0; a < 1000; a++) {
        for (ll b = 0; b < 1000; b++) {
            if (f(a) - f(b) == X) {
                cout << a << ' ' << b << '\n';
                return 0;
            }
            if (f(a) + f(b) == X) {
                cout << a << ' ' << -b << '\n';
                return 0;
            }
        }
    }
    return 0;
}

/**
 * 全探索
 */