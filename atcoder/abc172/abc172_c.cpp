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
    ll N, M, K;
    cin >> N >> M >> K;
    V<ll> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    V<ll> AC(N + 1, 0), BC(M + 1, 0);
    rep(i, N) AC[i + 1] = AC[i] + A[i];
    rep(i, M) BC[i + 1] = BC[i] + B[i];
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        ll rem = K - AC[i];
        if (rem < 0) continue;
        int ind = upper_bound(BC.begin(), BC.end(), rem) - BC.begin();
        ans = max(ans, i + ind - 1);
    }
    cout << ans << '\n';
    return 0;
}
