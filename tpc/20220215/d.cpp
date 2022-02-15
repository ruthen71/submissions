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

// 幾何テンプレートが長すぎるのでこれで許して(libraryの方にコードあります)
#include "../../../library/geometry/template.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, T;
    cin >> N >> T;
    V<Point> P(N);
    V<ll> ts(N);
    rep(i, N) cin >> P[i] >> ts[i];
    Double ans = 0;
    rep(i, N - 1) ans += distance_pp(P[i + 1], P[i]);
    V<Point> P2;
    for (ll tt = 0; tt < ts[N - 1]; tt += T) {
        int ind = upper_bound(ALL(ts), tt) - ts.begin();
        ind--;
        Point v = P[ind + 1] * (Double)(tt - ts[ind]) + P[ind] * (Double)(ts[ind + 1] - tt);
        v /= (Double)(ts[ind + 1] - ts[ind]);
        P2.push_back(v);
    }
    P2.push_back(P[N - 1]);
    Double ans2 = 0;
    int P2s = P2.size();
    rep(i, P2s - 1) ans2 += distance_pp(P2[i], P2[i + 1]);
    cout << fixed << setprecision(15) << (ans - ans2) * 100 / ans << '\n';
    return 0;
}
/**
 * 0, t, 2t, 3t, ... でどこにいるかを2分探索で求め、あとは距離を足していく
 */
