#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
using ld = long double;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

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
    if (N - M > K) return puts("0") & 0;
    mint ans = binomial(N + M, M, mint(0)) - binomial(N + M, M + K + 1, mint(0));
    cout << ans.val() << '\n';
    return 0;
}

/**
 * 二項係数
 * 折り返す
 * 格子の経路数で、直線を通ってはいけないものの場合の数
 * 初めに交わった交点で排反に場合分けし
 * 折り返すことで求める
 */