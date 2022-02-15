#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
const ll INF = 1ll << 60;

ll dx[7] = {0, 1, -1, 0, 0, 0, 0};
ll dy[7] = {0, 0, 0, 1, -1, 0, 0};
ll dz[7] = {0, 0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll A, B, C, N;
    cin >> A >> B >> C >> N;
    map<tuple<ll, ll, ll>, int> mp;
    vector<ll> x(N), y(N), z(N);
    rep(i, N) cin >> x[i] >> y[i] >> z[i];
    rep(i, N) {
        rep(k, 7) {
            ll nx = x[i] + dx[k], ny = y[i] + dy[k], nz = z[i] + dz[k];
            if (!(0 <= nx && nx < A)) continue;
            if (!(0 <= ny && ny < B)) continue;
            if (!(0 <= nz && nz < C)) continue;
            mp[{nx, ny, nz}] = 1;
        }
    }
    ll ans = 2 * (A * B + B * C + C * A);
    rep(i, N) {
        for (int k = 1; k < 7; k++) {
            ll nx = x[i] + dx[k], ny = y[i] + dy[k], nz = z[i] + dz[k];
            if (mp[{nx, ny, nz}])
                ans++;
            else
                ans--;
        }
        mp[{x[i], y[i], z[i]}] = 0;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 各立体を取り除いたときに、隣接する立体があるかによって、面が増えるか変わる
 */
