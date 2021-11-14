#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll INF = 1ll << 60;
const ld PI = 3.1415926535897932;
const ld EPS = 1e-9;

template <class T, class U>
using P = pair<T, U>;
template <class T>
using V2 = vector<vector<T>>;
template <class T>
using V3 = vector<vector<vector<T>>>;

ld calc(ld x1, ld y1, ld x2, ld y2) {
    ld ret = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return ret;
}

ld kaku(ld x1, ld y1, ld x2, ld y2) {
    // 弧度法で返す
    if (abs(x1 - x2) < EPS) {
        if (y2 - y1 > 0)
            return PI / 2;
        else
            return -PI / 2;
    }
    return atan2(y2 - y1, x2 - x1);
}

int main() {
    ll n;
    cin >> n;
    ld r, theta;
    cin >> r >> theta;
    theta = theta * PI / 180;
    vector<ld> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    V3<P<int, ld>> g(n + 1, V2<P<int, ld>>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) continue;
            for (int k = 1; k <= n; k++) {
                if (j == 0) {
                    if (i != k) g[i][j].push_back({k, calc(x[i], y[i], x[k], y[k])});
                } else {
                    ld alpha = kaku(x[j], y[j], x[i], y[i]);
                    ld beta = kaku(x[i], y[i], x[k], y[k]);
                    ld ganma = abs(alpha - beta);
                    if (min(2 * PI - ganma, ganma) <= theta + EPS && i != k) {
                        g[i][j].push_back({k, calc(x[i], y[i], x[k], y[k])});
                    }
                }
            }
        }
    }

    int R = (int)r + 5;
    ll V = (n + 1) * (n + 1) * R;
    V3<ld> dp(n + 1, V2<ld>(n + 1, vector<ld>(R, INF)));
    dp[1][0][0] = 0;
    priority_queue<P<ld, int>, vector<P<ld, int>>, greater<P<ld, int>>> pq;
    pq.push({0, (1 * (n + 1) + 0) * R + 0});
    while (!pq.empty()) {
        ld d = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        int ij = v / R, k = v % R;
        int i = ij / (n + 1), j = ij % (n + 1);
        if (dp[i][j][k] < d) continue;
        for (auto &e : g[i][j]) {
            if (dp[e.first][i][k + 1] > dp[i][j][k] + e.second) {
                dp[e.first][i][k + 1] = dp[i][j][k] + e.second;
                if (dp[e.first][i][k + 1] <= r) pq.push({dp[e.first][i][k + 1], (e.first * (n + 1) + i) * R + k + 1});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < R; k++) {
                if (dp[i][j][k] <= r) ans = max(ans, k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
幾何+グラフ
dp[i][j][k]=点iにいて、直前にいた点はjで、k個目の頂点であるときの最短距離
としたときに、もとめるものはdp[i][j][k]<=rなる最大のk
点j->iに移動している、という情報があれば、次に行ける点も決まるので、
ダイクストラ法が使える
*/