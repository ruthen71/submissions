#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

// g[u][k] = 頂点uからk番目に重みが小さい辺を通って行く先の点番号
// st[i][j] = deg=iとなる頂点に対し、ci=jとなるときの行先の頂点集合のZobrist Hash
int g[200005][9];
ll st[9][9];
ll full;
int perm[9];
int n, m, k, ans;

void rec(int i) {
    if (i == k) {
        ll cur = 0;
        rep(x, k) { cur ^= st[x][perm[x]]; }
        if (full == cur) ans++;
        return;
    }
    for (int x = 0; x <= i; x++) {
        perm[i] = x;
        rec(i + 1);
    }
    return;
}

int main() {
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());
    cin >> n >> m >> k;
    vector<int> eu(m), ev(m), deg(n, 0);
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--, w--;
        eu[w] = u;
        ev[w] = v;
    }
    rep(i, m) g[eu[i]][deg[eu[i]]++] = ev[i];
    uniform_int_distribution<ll> dist(0, INT64_MAX);
    vector<ll> r(n);
    rep(i, n) r[i] = dist(rnd);
    rep(i, n) rep(j, deg[i]) st[deg[i] - 1][j] ^= r[g[i][j]];
    rep(i, n) full ^= r[i];
    rec(0);
    cout << ans << '\n';
    return 0;
}

/**
 * Zobrist Hash
 * ゾブリストハッシュ
 * 状態をハッシュにする
 * ある順列(?)を定めると(例えば(1,2,2))(これは順列とは言わないが？)(問題文のcのやつ)
 * 各頂点から行ける頂点がただ1つに決まる
 *
 * どの頂点についてもいつか自分自身に戻ってこれる、の意味を冷静に考える
 * まず必要条件として、どの頂点についても少なくとも1つ以上の他の点からの行先でないと
 * 戻ってこれない(もし行先になってない頂点があれば、そこには戻れない)
 * ところで、各頂点につき行先はただ1つなのだから、行先は全部でNしかないですね……
 * ->行先の集合に1,2,...,Nが1回ずつ現れる
 * 逆にこの時、u->vの対応を置換で表すと巡回置換複数で表せて、巡回置換はサイクルグラフになる
 * ので、戻ってこれる(十分条件)
 * ↑こういうのあんまりやったことないのでかなり適当な証明だけど……
 * 結局行先集合に1...nが1つずつ現れればOK
 *
 * ところで出次数ごとにグラフをわけると、(1,2,2)というのは、c1として1を選んだときの行先集合
 * と、c2として2を選んだときの行先集合と、c3として2を選んだときの行先集合の和集合になる
 * それぞれは独立に計算できる
 * c1は1のみ、c2は1か2,...,ckは1~kのどれか、なので、全部で最大でも集合の個数は45個
 * 各々1~nが要素or要素でない、なので、O(N)で集合は列挙できる
 *
 * ...和集合演算どうするの？
 * Zobrist Hashを使う！
 * 1,2,...,Nを大きな乱数に対応させる!
 * これらのxorをあらかじめ計算しておく(コードのfullです)
 * 上記の各集合もxorを取ったものとして扱う
 * 和集合演算=集合ごとのxorを取ることでできる!
 * 最後にfullと一致するか見ればOK
 */