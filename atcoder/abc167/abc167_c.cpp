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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, X;
    cin >> N >> M >> X;
    V<int> C(N);
    V<V<int>> A(N, V<int>(M));
    rep(i, N) {
        cin >> C[i];
        rep(j, M) cin >> A[i][j];
    }
    int ans = 1 << 30;
    rep(b, 1 << N) {
        int cur = 0;
        V<int> AS(M, 0);
        rep(i, N) {
            if (b >> i & 1) {
                cur += C[i];
                rep(j, M) AS[j] += A[i][j];
            }
        }
        int ok = 1;
        rep(j, M) if (AS[j] < X) ok = 0;
        if (ok) ans = min(ans, cur);
    }
    cout << (ans == 1 << 30 ? -1 : ans) << '\n';
    return 0;
}

/**
 * bit全探索
 */
