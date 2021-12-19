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
    ll N, K;
    cin >> N >> K;
    vector<mint> ans(K);
    for (int i = 1; i <= K; i++) {
        ans[i - 1] = binomial(N - K + 1, i, mint(0)) * binomial(K - 1, K - i, mint(0));
    }
    rep(i, K) cout << ans[i].val() << '\n';
    return 0;
}

/**
 * 二項係数
 * 数え上げ
 * binomial(N-K+1,i)*binomial(K-1,K-i)(i=1,...,K)が答え
 */
