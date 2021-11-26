#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

ll INF = 1ll << 60;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    int m = 10000;
    rep(i, H) rep(j, W) m = min(m, A[i][j]);
    ll ans = 0;
    rep(i, H) rep(j, W) ans += A[i][j] - m;
    cout << ans << endl;
    return 0;
}
