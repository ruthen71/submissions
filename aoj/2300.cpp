#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<ld> L(N), A(N), B(N);
    rep(i, N) cin >> L[i] >> A[i] >> B[i];
    int N2 = 1 << N;
    ld ans = 0;
    rep(b, N2) {
        if (__builtin_popcount(b) != M) continue;
        ld s = 0;
        vector<int> ind;
        rep(i, N) if (b >> i & 1) ind.push_back(i);
        rep(i, M) {
            rep(j, i) {
                s += (L[ind[i]] - L[ind[j]]) * (L[ind[i]] - L[ind[j]]);
                s += (A[ind[i]] - A[ind[j]]) * (A[ind[i]] - A[ind[j]]);
                s += (B[ind[i]] - B[ind[j]]) * (B[ind[i]] - B[ind[j]]);
            }
        }
        ans = max(ans, s);
    }
    printf("%.15Lf\n", ans);
    return 0;
}

/**
 * N個の中からM個選んで、ペアの距離(L,A,Bの差の2乗)の総和を最大にする
 * bit全探索する
 */
