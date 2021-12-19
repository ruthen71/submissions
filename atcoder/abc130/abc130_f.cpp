#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

ll dx[100], dy[100];

ll INF = 500000000;

ld calc(vector<ll>& x, vector<ll>& y, vector<char>& d, ld t) {
    ld xmin = INF, xmax = -INF, ymin = INF, ymax = -INF;
    int N = x.size();
    rep(i, N) {
        xmin = min(xmin, x[i] + dx[d[i]] * t);
        xmax = max(xmax, x[i] + dx[d[i]] * t);
        ymin = min(ymin, y[i] + dy[d[i]] * t);
        ymax = max(ymax, y[i] + dy[d[i]] * t);
    }
    return (xmax - xmin) * (ymax - ymin);
}

int main() {
    dx['R'] = 1, dx['L'] = -1, dx['U'] = 0, dx['D'] = 0;
    dy['R'] = 0, dy['L'] = 0, dy['U'] = 1, dy['D'] = -1;
    int N;
    cin >> N;
    vector<ll> x(N), y(N);
    vector<char> d(N);
    rep(i, N) cin >> x[i] >> y[i] >> d[i];
    vector<ld> cpv = {0};  // change points vector
    // cpvに0を入れておくのを忘れずに
    // ref:https://drken1215.hatenablog.com/entry/2019/06/22/022600
    {  // x方向最大値
        ll m1 = -INF, m2 = -INF, m3 = -INF;
        rep(i, N) {
            if (d[i] == 'R') m1 = max(m1, x[i]);
            if (d[i] == 'L') m2 = max(m2, x[i]);
            if (d[i] == 'U' || d[i] == 'D') m3 = max(m3, x[i]);
        }
        if (m1 != -INF && m2 != -INF) cpv.push_back((ld)abs(m1 - m2) / 2);
        if (m1 != -INF && m3 != -INF) cpv.push_back((ld)abs(m1 - m3));
        if (m2 != -INF && m3 != -INF) cpv.push_back((ld)abs(m2 - m3));
    }
    {  // x方向最小値
        ll m1 = INF, m2 = INF, m3 = INF;
        rep(i, N) {
            if (d[i] == 'R') m1 = min(m1, x[i]);
            if (d[i] == 'L') m2 = min(m2, x[i]);
            if (d[i] == 'U' || d[i] == 'D') m3 = min(m3, x[i]);
        }
        if (m1 != INF && m2 != INF) cpv.push_back((ld)abs(m1 - m2) / 2);
        if (m1 != INF && m3 != INF) cpv.push_back((ld)abs(m1 - m3));
        if (m2 != INF && m3 != INF) cpv.push_back((ld)abs(m2 - m3));
    }
    {  // y方向最大値
        ll m1 = -INF, m2 = -INF, m3 = -INF;
        rep(i, N) {
            if (d[i] == 'U') m1 = max(m1, y[i]);
            if (d[i] == 'D') m2 = max(m2, y[i]);
            if (d[i] == 'R' || d[i] == 'L') m3 = max(m3, y[i]);
        }
        if (m1 != -INF && m2 != -INF) cpv.push_back((ld)abs(m1 - m2) / 2);
        if (m1 != -INF && m3 != -INF) cpv.push_back((ld)abs(m1 - m3));
        if (m2 != -INF && m3 != -INF) cpv.push_back((ld)abs(m2 - m3));
    }
    {  // y方向最小値
        ll m1 = INF, m2 = INF, m3 = INF;
        rep(i, N) {
            if (d[i] == 'U') m1 = min(m1, y[i]);
            if (d[i] == 'D') m2 = min(m2, y[i]);
            if (d[i] == 'R' || d[i] == 'L') m3 = min(m3, y[i]);
        }
        if (m1 != INF && m2 != INF) cpv.push_back((ld)abs(m1 - m2) / 2);
        if (m1 != INF && m3 != INF) cpv.push_back((ld)abs(m1 - m3));
        if (m2 != INF && m3 != INF) cpv.push_back((ld)abs(m2 - m3));
    }
    ld ans = numeric_limits<ld>::max();
    for (auto& t : cpv) {
        ans = min(ans, calc(x, y, d, t));
    }
    printf("%.15Lf\n", ans);
    return 0;
}

/**
 * 幾何
 * イベント列挙
 * 嘘解法で通した
 * 三分探索(3分探索)は嘘解法！！！
 * 各方向で分けて考えたときの変化量が変化するときを列挙
 * (例えば、それまでずっとx方向の最大値を担っていた点を、別の点が追い越すなど)
 * 加えて、t=0のときも含めると、タイミングはこれらのいずれかになる
 * (x,yともに増える/減るは良いとして、片方が増えるときには上に凸になるらしい)
 * ということでこれらのminを取る
 * イベントの列挙方法はけんちょん氏の記事を参考にした
 * https://drken1215.hatenablog.com/entry/2019/06/22/022600
 *
 */