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
using ld = long double;
const ld PI = acos(-1);
const ll INF = 1LL << 60;
const ll XM = 60 * 60 * 360;

void solve() {
    ll r, theta, n, m, s;
    cin >> r >> n >> theta >> m >> s;
    ll x = (theta * 60 + m) * 60 + s;
    V<int> rem(XM, 0);
    rep(i, n) {
        if (rem[x * i % XM]) break;
        rem[x * i % XM] = 1;
    }
    V<ll> ang;
    rep(i, XM) if (rem[i]) ang.push_back(i);
    show(ang);
    int len = ang.size();
    show(len);
    ll lb = XM - ang[len - 1];
    rep(i, len - 1) lb = max(lb, abs(ang[i + 1] - ang[i]));
    show(lb);
    show((ld)lb / XM);
    ld ans = (ld)r * r * PI * lb / XM;
    cout << fixed << setprecision(15) << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}

/**
 * 鳩ノ巣原理より、Nは10^8と大きいが、実際には360*60*60回以内にループするのでそこで終わりにする
 */
