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
    int N;
    cin >> N;
    V<ll> A(N);
    rep(i, N) cin >> A[i];
    ll c = 0;
    for (int i = 2; i < N; i++) c ^= A[i];
    if (A[0] + A[1] - c >= 0 && (A[0] + A[1] - c) % 2 == 0) {
        ll ans = (A[0] + A[1] - c) / 2;
        if (ans & c || ans > A[0]) {
            cout << -1 << '\n';
            return 0;
        }
        for (int i = 40; i >= 0; i--) {
            if (c >> i & 1) {
                if (ans + (1LL << i) <= A[0]) {
                    ans += 1LL << i;
                }
            }
        }
        cout << (ans == 0 ? -1 : A[0] - ans) << '\n';
        return 0;
    }
    cout << -1 << '\n';
    return 0;
}

/**
 * XOR問題
 * Nim
 */