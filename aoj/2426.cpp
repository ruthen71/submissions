#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll INF = 1ll << 60;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    vector<ll> xs = {-INF, INF}, ys = {-INF, INF};
    rep(i, n) {
        xs.push_back(x[i]);
        ys.push_back(y[i]);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    rep(i, n) {
        x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin();
        y[i] = lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin();
    }
    ll H = xs.size(), W = ys.size();
    vector<vector<ll>> cum(H + 1, vector<ll>(W + 1, 0));
    rep(i, n) { cum[x[i]][y[i]]++; }
    rep(i, H) rep(j, W) cum[i + 1][j + 1] += cum[i + 1][j] + cum[i][j + 1] - cum[i][j];
    rep(q, m) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x2++, y2++;
        x1 = lower_bound(xs.begin(), xs.end(), x1) - xs.begin();
        x2 = lower_bound(xs.begin(), xs.end(), x2) - xs.begin();
        y1 = lower_bound(ys.begin(), ys.end(), y1) - ys.begin();
        y2 = lower_bound(ys.begin(), ys.end(), y2) - ys.begin();
        ll ans = cum[x2 - 1][y2 - 1] - cum[x2 - 1][y1 - 1] - cum[x1 - 1][y2 - 1] + cum[x1 - 1][y1 - 1];
        printf("%lld\n", ans);
    }
    return 0;
}

/*
二次元座圧+二次元累積和
めちゃくちゃバグらせた
二次元累積和をちゃんと理解してない気がする
半開区間になっているからy2やx2も-1する必要がある
*/
