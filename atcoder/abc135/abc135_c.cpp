#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> A(N + 1), B(N);
    rep(i, N + 1) cin >> A[i];
    rep(i, N) cin >> B[i];
    ll ans = 0;
    rep(i, N) {
        ans += min(A[i], B[i]);
        B[i] -= min(A[i], B[i]);
        if (i < N) {
            ans += min(A[i + 1], B[i]);
            A[i + 1] -= min(A[i + 1], B[i]);
        }
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 前から貪欲
 */
