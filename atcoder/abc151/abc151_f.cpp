#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = double;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const ld EPS = 1e-8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ld> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    ld ans = 1e12;
    // 2点を直径とする場合
    rep(i, N) {
        rep(j, i) {
            ld X = (x[i] + x[j]) / 2, Y = (y[i] + y[j]) / 2;
            ld r = 0;
            rep(k, N) r = max(r, hypot(x[k] - X, y[k] - Y));
            ans = min(ans, r);
        }
    }
    // 3点を頂点とする三角形の外心となる場合
    rep(i, N) {
        rep(j, i) {
            rep(k, j) {
                ld x1 = x[j] - x[i], y1 = y[j] - y[i], x2 = x[k] - x[i], y2 = y[k] - y[i];
                if (abs(x1 * y2 - x2 * y1) <= EPS) continue;
                ld Y = (x2 * (x1 * x1 + y1 * y1) - x1 * (x2 * x2 + y2 * y2)) / 2 / (y1 * x2 - y2 * x1);
                ld X = (y2 * (x1 * x1 + y1 * y1) - y1 * (x2 * x2 + y2 * y2)) / 2 / (x1 * y2 - x2 * y1);
                X += x[i];
                Y += y[i];
                ld r = 0;
                rep(l, N) r = max(r, hypot(x[l] - X, y[l] - Y));
                ans = min(ans, r);
            }
        }
    }
    printf("%.15lf\n", ans);
    return 0;
}

/**
 * 最小包含円
 * 2点が円の半径になるか、3点から成る三角形の外心となる場合を全探索する
 * X += x[i];
 * Y += y[i];
 * を忘れて1時間半溶かした
 * 幾何ライブラリを整備しようと思った
 */
