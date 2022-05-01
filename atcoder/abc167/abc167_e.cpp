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

#include <atcoder/modint>
using mint = atcoder::modint998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, M, K;
    cin >> N >> M >> K;
    mint ans = 0;
    V<mint> pm(N + 1, 1), facl(N + 1, 1);
    rep(i, N) pm[i + 1] = pm[i] * (M - 1);
    rep(i, N) facl[i + 1] = facl[i] * (i + 1);
    for (int L = 0; L <= K; L++) {
        ans += M * pm[N - L - 1] * facl[N - 1] / facl[N - 1 - L] / facl[L];
    }
    cout << ans.val() << '\n';
    return 0;
}

/**
 * 二項係数
 * 数え上げ
 */