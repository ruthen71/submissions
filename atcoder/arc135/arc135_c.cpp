#include <bits/stdc++.h>
using namespace std;
// clang-format off
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
template <class T> using V = vector<T>;
// clang-format on

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    V<ll> A(N);
    rep(i, N) cin >> A[i];
    V<ll> c(30, 0);
    rep(b, 30) {
        rep(i, N) {
            if (A[i] >> b & 1) c[b]++;
        }
    }
    ll ans = 0;
    rep(i, N) ans += A[i];
    rep(i, N) {
        ll cc = 0;
        rep(b, 30) {
            if (A[i] >> b & 1) {
                ll x = 1 << b;
                cc += x * (N - c[b]);
            } else {
                ll x = 1 << b;
                cc += x * c[b];
            }
        }
        ans = max(ans, cc);
    }
    cout << ans << '\n';
    return 0;
}

/**
 * XOR
 * 操作回数は高々1回
 */
