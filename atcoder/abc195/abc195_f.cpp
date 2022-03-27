#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

vector<int> Era_list(int n) {
    vector<int> isprime(n + 1, 1);
    vector<int> res;
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) {
            res.push_back(i);
            for (int j = 2 * i; j < n + 1; j += i) isprime[j] = 0;
        }
    }
    return res;
}

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T> using V = vector<T>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll A, B;
    cin >> A >> B;
    auto res = Era_list(72);
    ll N = res.size(), M = B - A + 1;
    ll N2 = 1 << N;
    V<V<ll>> dp(M + 1, V<ll>(N2, 0));
    dp[0][0] = 1;
    for (ll x = A; x <= B; x++) {
        ll i = x - A;
        ll nx = 0;
        rep(j, N) {
            if (x % res[j] == 0) {
                nx |= 1 << j;
            }
        }
        rep(b, N2) {
            dp[i + 1][b] += dp[i][b];
            if (b & nx) continue;
            dp[i + 1][b | nx] += dp[i][b];
        }
    }
    ll ans = accumulate(dp[M].begin(), dp[M].end(), 0LL);
    cout << ans << '\n';
    return 0;
}