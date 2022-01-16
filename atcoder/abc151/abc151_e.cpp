#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

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

using mint = modint1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    mint ans = 0;
    vector<mint> bino(N - K + 1);
    bino[0] = binomial(N - 1, K - 1, mint(0));
    rep(i, N - K) bino[i + 1] = (N - K - i) * bino[i] / (N - 1 - i);
    sort(ALL(A));
    rep(i, N + 1 - K) ans -= A[i] * bino[i];
    reverse(ALL(A));
    rep(i, N + 1 - K) ans += A[i] * bino[i];
    cout << ans.val() << '\n';
    return 0;
}

/**
 * 寄与を考える系
 * maxとminに分けて、それぞれを組合せ公式で求める
 * min=A[i]*binomial(N-1-i,K-1)をi=0...N-Kまで(Aは昇順)
 * max=A[i]*binomial(N-1-i,K-1)をi=0...N-Kまで(Aは降順)
 */
