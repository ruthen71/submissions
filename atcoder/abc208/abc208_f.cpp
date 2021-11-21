#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

using mint = modint1000000007;

// 点(x[0],y[0]),...,(x[N],y[N])を通るN次多項式P(x)に対し、P(T)を求める
template <class Mint>
Mint lagrange_interpolation(vector<Mint>& x, vector<Mint>& y, long long T) {
    assert(x.size() > 0);
    int N = x.size() - 1;  // degree
    Mint d = x[1] - x[0];  // x[i]=x[0]+i*d
    vector<Mint> invfac(N + 1, 1);
    Mint fac = 1;
    for (int i = 1; i <= N; i++) fac *= (i * d);
    invfac[N] = fac.inv();
    for (int i = N - 1; i > 0; i--) invfac[i] = invfac[i + 1] * (i + 1) * d;

    // dp=左からの累積積,pd=右からの累積積
    vector<Mint> dp(N + 1, 1), pd(N + 1, 1);
    for (int i = 1; i <= N; i++) dp[i] = dp[i - 1] * (T - x[i - 1]);
    for (int i = N - 1; i >= 0; i--) pd[i] = pd[i + 1] * (T - x[i + 1]);
    Mint ret = 0;
    for (int i = 0; i <= N; i++) {
        Mint tmp = y[i] * dp[i] * pd[i] * invfac[i] * invfac[N - i];
        if ((N - i) & 1) tmp *= -1;
        ret += tmp;
    }
    return ret;
}

int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<mint> A(M + K + 1);
    for (int i = 0; i <= M + K; i++) A[i] = mint(i).pow(K);
    rep(t, M) for (int i = 1; i <= M + K; i++) A[i] = A[i - 1] + A[i];
    vector<mint> X(M + K + 1);
    iota(X.begin(), X.end(), 0);
    mint ans = lagrange_interpolation(X, A, N);
    cout << ans.val() << endl;
    return 0;
}

/*
解説AC
多項式
ラグランジュ補間
ラグランジュ多項式
f(n,m)がnについてのm+k次多項式になる(これに気づくのが難しいし、証明も結構大変)
n=0,...,m+kに対する多項式の値を求めて、ラグランジュ補間をする
*/