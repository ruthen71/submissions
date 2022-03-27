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
    int N, M;
    cin >> N >> M;
    V<ll> A(N + 1), C(N + M + 1);
    rep(i, N + 1) cin >> A[i];
    rep(i, N + M + 1) cin >> C[i];
    V<ll> B(M + 1);
    for (int k = M; k >= 0; k--) {
        ll cur = C[k + N];
        rep(i, N + 1) {
            rep(j, M + 1) {
                if (i + j == k + N && i != N) {
                    cur -= A[i] * B[j];
                }
            }
        }
        B[k] = cur / A[N];
    }
    rep(i, B.size()) cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
    show(B);
    return 0;
}