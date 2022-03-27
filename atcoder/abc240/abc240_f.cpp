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

void solve() {
    ll N, M;
    cin >> N >> M;
    V<ll> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    ll ans = x[0], sumc = 0, sums = 0;
    rep(i, N) {
        if (sumc + x[i] > 0 && sumc + x[i] * y[i] < 0) {
            ll lb = 1, ub = y[i];  // [lb, ub)
            while (ub - lb > 1) {
                ll mid = (ub + lb) / 2;
                if (sumc + x[i] * mid > 0)
                    lb = mid;
                else
                    ub = mid;
            }
            ans = max(ans, sums + lb * (lb + 1) / 2 * x[i] + sumc * lb);
        }
        // update sums
        sums += y[i] * (y[i] + 1) / 2 * x[i] + sumc * y[i];
        sumc += x[i] * y[i];
        // update ans
        ans = max(ans, sums);
    }
    cout << ans << '\n';
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
 * 難しい
 * BはAを微分したもの
 * A[i]のA[i-1]からの変化量としてはC[0]+C[1]+...+C[i]=B[i]
 * これの正負で場合分けする
 * 最初B>0で最後B>=0 -> Aは増え続けるので右端で最大
 * 最初B<=0で最後B<0 -> Aは減り続けるので左端で最大
 * 最初B<=0で最後B>=0 -> Aは下に凸の放物線(っぽくなる(離散))なので両端のどちらかで最大
 * 最初B>0で最後B<0 -> Aは上に凸の放物線なので極大値がある、これを二分探索で求める
 * 放物線だがB(傾き)のほうなら単調減少なので三分探索しなくて良い(というかO(1)で求められる)(けどミスが怖いので)
 */
