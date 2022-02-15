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

void solve() {
    Line L;
    cin >> L;
    int N;
    cin >> N;
    V<string> S(N);
    V<Point> P(N);
    rep(i, N) cin >> S[i] >> P[i];
    V<int> anss = {0};
    for (int i = 1; i < N; i++) {
        if (sign(distance_lp(L, P[i]) - distance_lp(L, P[anss[0]])) < 0) {
            anss = {i};
        } else if (equals(distance_lp(L, P[i]), distance_lp(L, P[anss[0]]))) {
            anss.push_back(i);
        }
    }
    rep(i, anss.size()) cout << S[anss[i]] << (i == anss.size() - 1 ? '\n' : ' ');
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
 * 点と直線の距離を求めるライブラリがあればやるだけだが、誤差が厳しい
 */
