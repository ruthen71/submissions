#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<ll> B(N - 1);
    rep(i, N - 1) cin >> B[i];
    ll ans = B[0] + B[N - 2];
    rep(i, N - 2) ans += min(B[i], B[i + 1]);
    cout << ans << '\n';
    return 0;
}
