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

#include <atcoder/lazysegtree>
using namespace atcoder;

// ref:https://betrue12.hateblo.jp/entry/2020/09/23/005940

using S = long long;
using F = long long;

const S INF = 8e18;
const F ID = 8e18;

S op(S a, S b) { return std::max(a, b); }
S e() { return 0LL; }
S mapping(F f, S x) { return (f == ID ? x : f); }
F composition(F f, F g) { return (f == ID ? g : f); }
F id() { return ID; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    V<tuple<int, int, int>> A(N);
    rep(i, N) {
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        A[i] = {y, x1, x2};
    }
    sort(ALL(A));
    ll ans = 0;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(10050);
    rep(i, N) {
        int y = get<0>(A[i]), x1 = get<1>(A[i]), x2 = get<2>(A[i]);
        ans += y - seg.get(x1);
        ans += y - seg.get(x2 - 1);
        seg.apply(x1, x2, y);
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 高さが低い順に見る
 * 高さの更新は遅延セグメントツリーで頑張る
 */
