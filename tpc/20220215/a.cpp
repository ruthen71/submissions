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

void solve(int n) {
    V<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    V<int> s(2, 0);
    rep(i, n) {
        if (x[i] == x[n / 2] || y[i] == y[n / 2]) continue;
        if ((x[i] - x[n / 2]) * (y[i] - y[n / 2]) > 0)
            s[0]++;
        else
            s[1]++;
    }
    cout << s[0] << ' ' << s[1] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n, n != 0) solve(n);
    return 0;
}

/**
 * どこで4分割するんだ->n/2番目とOUTPUTに書かれていた……
 */
