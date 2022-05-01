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
using namespace atcoder;
using mint = modint1000000007;
ostream &operator<<(ostream &os, const mint &p) { return os << p.val(); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, M;
    cin >> N >> M;
    V<mint> facl(M + 1, 1), inv(M + 1, 1);
    for (int i = 1; i <= M; i++) facl[i] = i * facl[i - 1];
    inv[M] = 1 / facl[M];
    for (int i = M - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1);
    mint ans = 0;
    for (int k = 0; k <= N; k++) {
        if (k % 2 == 0)
            ans += facl[N] * inv[k] * inv[N - k] * facl[M - k] * inv[M - N];
        else
            ans -= facl[N] * inv[k] * inv[N - k] * facl[M - k] * inv[M - N];
    }
    ans *= facl[M] * inv[M - N];
    cout << ans.val() << '\n';
    return 0;
}

/**
 * 数え上げ
 * 二項係数
 * 攪乱順列
 * 完全順列
 * 包除原理
 * https://manabitimes.jp/math/612
 */