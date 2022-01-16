#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void solve(int N) {
    vector<ld> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    int ans = 1;
    rep(i, N) {
        rep(j, i) {
            // i,jがそれぞれ円周上にあるような半径1の円の中心を求める
            ld d = hypot(x[i] - x[j], y[i] - y[j]);
            if (d > 2) continue;
            ld d2 = d / 2;
            ld h = sqrt(1 - d2 * d2);
            ld cx = (x[i] + x[j]) / 2, cy = (y[i] + y[j]) / 2;
            ld px = y[i] - y[j], py = x[j] - x[i];
            rep(_, 2) {
                ld ox = cx + px * h / d, oy = cy + py * h / d;
                int cnt = 2;
                rep(k, N) {
                    if (k == i || k == j) continue;
                    if ((ox - x[k]) * (ox - x[k]) + (oy - y[k]) * (oy - y[k]) <= 1) cnt++;
                }
                ans = max(ans, cnt);
                px *= -1;
                py *= -1;
            }
        }
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while (cin >> N, N) solve(N);
    return 0;
}

/**
 * 幾何
 * ギリギリを考える典型
 * 距離が2以下(制約より未満としても良いが)の点を2つ選び
 * 2点を通る半径1の円は2個ある
 * 両方の中心を調べる
 * これを全部のペアに対してやればOK
 */
