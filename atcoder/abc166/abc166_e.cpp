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
    ll N;
    cin >> N;
    V<ll> A(N);
    rep(i, N) cin >> A[i];
    map<ll, ll> mp;
    ll ans = 0;
    rep(i, N) {
        ans += mp[i - A[i]];
        mp[i + A[i]]++;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * Zero-Sum Ranges
 */