#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) begin(x), end(x)
template <class T> using V = vector<T>;

const ll dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const ll dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ok = 0;
    rep(k, 8) {
        ll nx = x1 + dx[k], ny = y1 + dy[k];
        if ((x2 - nx) * (x2 - nx) + (y2 - ny) * (y2 - ny) == 5) {
            ok = 1;
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}

/**
 * 近傍を探索する
 */
