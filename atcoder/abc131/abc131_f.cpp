#include <bits/stdc++.h>
using namespace std;

#include <atcoder/dsu>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

vector<int> compress(vector<int> a) {
    vector<int> b = a;
    sort(ALL(b));
    b.erase(unique(ALL(b)), b.end());
    for (auto &ai : a) ai = lower_bound(ALL(b), ai) - b.begin();
    return a;
}

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    x = compress(x);
    y = compress(y);
    int X = 0, Y = 0;
    rep(i, N) X = max(X, x[i] + 1), Y = max(Y, y[i] + 1);
    vector<vector<int>> g(X);
    rep(i, N) { g[x[i]].push_back(y[i]); }
    dsu uf(Y);
    rep(i, X) {
        for (auto yi : g[i]) {
            uf.merge(yi, g[i][0]);
        }
    }
    vector<set<int>> g2(Y);
    rep(i, N) { g2[uf.leader(y[i])].insert(x[i]); }
    ll ans = 0;
    rep(j, Y) {
        if (uf.leader(j) == j) {
            ans += (ll)uf.size(j) * g2[j].size();
        }
    }
    ans -= N;
    cout << ans << '\n';
    return 0;
}

/**
 * まずサンプル3の大きいバージョンから、全列挙は無理そうと考える
 * 最終状態の点の数-Nが答えなので最終状態を考えたい
 *
 * まずyが2通りの値しか取らない場合を考える(yi=0または1とする)
 * yi=0となるxiの集合と、yi=1となるxiの集合をそれぞれ列挙する
 * この集合に共通要素がないとき、操作はできない
 * 証明
 * 操作は長方形の3点がないとダメ
 * x座標が同じでy座標が異なる点のペアがないとダメ
 * そのような点のペアは上記の条件では存在しない
 * 共通要素があるとき->2つの集合をそれぞれ和集合に更新
 * これをいろんなyiのペアに対し繰り返せばいつか止まる
 * (が、間に合わない)
 * 結局yiとyjに対してそれぞれ決まる集合をマージしているイメージなので、
 * yiyjの選ぶ順番を意識せず、最初にyiごとにグラフを連結させておく
 * そうすると連結成分のyiに対するxの集合は全て最終的には同じになる
 * よって連結成分ごとに集合を1つ代表して管理すればOK
 */