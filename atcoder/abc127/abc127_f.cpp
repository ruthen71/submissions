#include <bits/stdc++.h>
using namespace std;

#include <atcoder/fenwicktree>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const ll INF = 1ll << 60;

int main() {
    ll Q;
    cin >> Q;
    vector<ll> t(Q), a(Q), b(Q);
    rep(i, Q) {
        cin >> t[i];
        if (t[i] == 2) continue;
        cin >> a[i] >> b[i];
    }
    ll t1 = 0, bs = 0;
    vector<pair<ll, int>> va;  // {a_i, i}
    rep(i, Q) {
        if (t[i] == 1) {
            t1++;
            va.push_back({a[i], i});
            bs += b[i];
        }
    }
    sort(ALL(va));
    vector<ll> ato(Q);  // query_id->a_iがソートした後何番目か
    fenwick_tree<ll> fw1(t1), fw2(t1);
    int fws = t1;
    rep(i, t1) {
        ato[va[i].second] = i;
        fw1.add(i, va[i].first);
        fw2.add(i, 1);
    }
    vector<ll> ansx(Q), ansfx(Q);
    for (int i = Q - 1; i >= 0; i--) {
        if (t[i] == 1) {
            // change f(x)
            fw1.add(ato[i], -a[i]);
            fw2.add(ato[i], -1);
            bs -= b[i];
            t1--;
        } else {
            // calc f(x)
            int ok = fws, ng = 0;
            while (ok - ng > 1) {
                int md = (ok + ng) / 2;
                ll nums = fw2.sum(0, md);
                if (nums >= (t1 + 1) / 2)
                    ok = md;
                else
                    ng = md;
            }
            ansx[i] = fw1.sum(ok - 1, ok);
            ansfx[i] = fw1.sum(ok, fws) - fw1.sum(0, ok) + bs;
            if (t1 & 1) ansfx[i] += ansx[i];
        }
    }
    rep(i, Q) if (t[i] == 2) cout << ansx[i] << " " << ansfx[i] << '\n';
    return 0;
}

/**
 * クエリ問題
 * 逆順に処理
 * BIT, Fenwick Tree, フェニック木
 * まずクエリを全て読んで置き、逆順に処理する
 * a_iを昇順に並べて
 * fw1 = [a_0, a_1, ..., a_{t1-1}](取っちゃったa_iは0にする)
 * fw2 = [a_iがまだ存在するなら1, 存在しないなら0(i=0,...,t1-1)]
 * クエリ1について
 * うまくfw1とfw2を変更できればOK
 * クエリ番号iに対し、a_iが全体で何番目かがわかれば、fw1とfw2におけるその値を0にする
 * クエリ2について
 * x=残っているaたちの中央値
 * fw2.sum(0, r)がまだ残っている要素数の半分以上となる最小のrに対し、
 * r-1が中央値の(フェニック木における)位置となる
 * fw1[r-1]=fw1.sum(r-1,r)がargmin{f(x)}
 * そのときの値(f(x))は、abs()の中身が+になる部分と-になる部分でだいたいxは打ち消し合うので
 * a_iの部分が重要で、それをフェニック木のsumで求める
 * slope-trickを使うと楽らしい
 */
