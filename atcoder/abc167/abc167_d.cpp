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
    ll N, K;
    cin >> N >> K;
    V<int> A(N);
    rep(i, N) cin >> A[i];
    V<V<int>> db(60, V<int>(N, -1));
    rep(i, N) db[0][i] = A[i] - 1;
    for (int i = 1; i < 60; i++) {
        rep(j, N) db[i][j] = db[i - 1][db[i - 1][j]];
    }
    int c = 0;
    for (int i = 60; i >= 0; i--) {
        if (K >> i & 1) {
            c = db[i][c];
        }
    }
    cout << c + 1 << '\n';
    return 0;
}

/**
 * ダブリング
 */