#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<ll> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    ll ans = 0;
    rep(_, 4) {
        rep(i, N) {
            ll c = y[i];
            y[i] = x[i];
            x[i] = -c;
        }
        ll sx = 0, sy = 0;
        vector<ll> cx, cy;
        rep(i, N) {
            if (x[i] >= 0 && y[i] >= 0)
                sx += x[i], sy += y[i];
            else if (x[i] > 0 || y[i] > 0)
                cx.push_back(x[i]), cy.push_back(y[i]);
        }
        ans = max(ans, sx * sx + sy * sy);
        map<ll, ll> mp;
        mp[sx] = sy;
        int m = cx.size();
        rep(i, m) {
            map<ll, ll> mp2 = mp;  // new
            for (auto &p : mp) {
                // (p.first,p.second) -> (p.first+cx[i],p.second+cy[i])
                if (p.first + cx[i] < 0) continue;
                mp2[p.first + cx[i]] = max(p.second + cy[i], mp2[p.first + cx[i]]);
            }
            vector<pair<ll, ll>> mpc;
            for (auto &p : mp2) mpc.push_back(make_pair(p.second, p.first));
            sort(ALL(mpc));
            reverse(ALL(mpc));
            ll cmx = 0;
            mp.clear();
            for (auto &p : mpc) {
                if (p.second >= cmx) {
                    mp[p.second] = p.first;
                    cmx = p.second;
                }
            }
        }
        for (auto &p : mp) {
            ans = max(ans, p.first * p.first + p.second * p.second);
        }
    }
    printf("%.15Lf\n", (ld)sqrt(ans));
    return 0;
}

/**
 * 偏角ソート
 * 選ぶエンジンの集合は偏角ソート後に連続する部分を取ったものになる
 * 提出:https://atcoder.jp/contests/abc139/submissions/28311180
 * 90度回転
 * 自分の解法
 * まず、90度回転を4回することにして、
 * 答えの(X,Y)が第一象限(境界含む)にあるとする
 * (x_i,y_i)について
 * x_i>=0&&y_i>=0は全て取る
 * 残りは(x,y)=(+,-),(0,-),(-,+),(-,0),(-,-)だが
 * このうち取る可能性があるのは(+,-)か(-,+)か
 * これらをvectorに追加する
 * 各xに対して最大のy以外は不要なので、map<ll,ll>(mp[x]=y)として
 * 最大値を更新
 * 普通にやるとTLEするが、各更新後について
 * yの降順に見て、xが今まで見たやつより小さいやつは不要なので使わない
 * ^
 * |
 * |o
 * |      o
 * |   x
 * |           o
 * |         x
 * |     x
 * |               o
 * --------------------------->
 * という枝刈りをすると通る(上図のoだけ残すという枝刈り)
 */
