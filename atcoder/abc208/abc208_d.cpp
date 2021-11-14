#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll INF = 1ll << 60;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> d(N, vector<ll>(N, INF));
    rep(i, N) d[i][i] = 0;
    ll ans = 0;
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = c;
    }
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                if (d[i][j] != INF) ans += d[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
ワーシャルフロイド法の仕組みがdpの配列再利用であることを知っていると解ける
*/
