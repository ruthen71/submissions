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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll M, N;
    ld R;
    cin >> M >> N >> R;
    ll sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    ld ans = INF;
    for (int i = 0; i <= N; i++) {
        ld c = 0;
        c += abs(sy - i) * R / N;
        c += i * R / N * PI * abs(sx - gx) / M;
        c += abs(gy - i) * R / N;
        ans = min(ans, c);
    }
    cout << fixed << setprecision(15) << ans << '\n';
    return 0;
}

/**
 * スタート地点からx座標同じでy座標のどこかまで行き、そこからゴール地点のx座標まで行き
 * そこからゴール地点のy座標まで行く
 * どこか、を全探索する
 */
