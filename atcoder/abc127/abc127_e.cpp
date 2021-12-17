#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

using mint = modint1000000007;

template <class Mint>
Mint binomial(long long N, long long K, Mint T) {
    if (N < 0 || K < 0 || N < K) return 0;
    Mint ret1 = 1, ret2 = 1;
    K = min(K, N - K);
    for (long long i = 1; i <= K; i++) {
        ret1 *= N--;
        ret2 *= i;
    }
    return ret1 / ret2;
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    mint ans = 0;
    // rep(x1, N) rep(y1, M) rep(x2, N) rep(y2, M) ans += abs(x1 - x2) + abs(y1 - y2);
    // ↓
    // rep(x1, N) rep(y1, M) rep(x2, N) rep(y2, M) ans += abs(x1 - x2);
    // rep(x1, N) rep(y1, M) rep(x2, N) rep(y2, M) ans += abs(y1 - y2);
    // ↓
    // rep(x1, N) rep(x2, N) ans += M * M * abs(x1 - x2);
    // rep(y1, M) rep(y2, M) ans += N * N * abs(y1 - y2);
    // ↓
    // rep(x1, N) rep(x2, x1) ans += 2 * M * M * abs(x1 - x2);
    // rep(y1, M) rep(y2, y1) ans += 2 * N * N * abs(y1 - y2);
    // ↓
    // rep(x1, N) rep(x2, x1) ans += 2 * M * M * (x1 - x2);
    // rep(y1, M) rep(y2, y1) ans += 2 * N * N * (y1 - y2);
    // ↓
    // rep(x1, N) ans += 2 * M * M * x1 * (x1 + 1) / 2;
    // rep(y1, M) ans += 2 * N * N * y1 * (y1 + 1) / 2;
    // ↓
    // rep(x1, N) ans += M * M * x1 * (x1 + 1);
    // rep(y1, M) ans += N * N * y1 * (y1 + 1);
    // ↓
    ans += M * M * (N - 1) * N * (N + 1) / 3;
    ans += N * N * (M - 1) * M * (M + 1) / 3;
    ans *= binomial(N * M - 2, K - 2, mint(0));
    ans /= 2;
    cout << ans.val() << '\n';
    return 0;
}

/**
 * rep(x1, N) rep(y1, M) rep(x2, N) rep(y2, M) ans += abs(x1 - x2) + abs(y1 - y2);
 * の展開にめちゃくちゃ時間かかって悲しい気持ちになった
 */
