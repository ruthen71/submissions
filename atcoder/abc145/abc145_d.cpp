#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

template <class Mint> Mint binomial(long long N, long long K) {
    if (N < 0 || K < 0 || N < K) return 0;
    Mint ret1 = 1, ret2 = 1;
    K = min(K, N - K);
    for (long long i = 1; i <= K; i++) {
        ret1 *= N--;
        ret2 *= i;
    }
    return ret1 / ret2;
}

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T> using V = vector<T>;

#include <atcoder/modint>
using namespace atcoder;
using mint = modint1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int X, Y;
    cin >> X >> Y;
    if (2 * Y - X >= 0 && (2 * Y - X) % 3 == 0 && 2 * X - Y >= 0 && (2 * X - Y) % 3 == 0) {
        int a = (2 * Y - X) / 3, b = (2 * X - Y) / 3;
        cout << binomial<mint>(a + b, a).val() << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}
