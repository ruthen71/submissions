#include <bits/stdc++.h>
using namespace std;

template <class T>
struct segtree {
    // ↓↓↓↓↓ change here! ↓↓↓↓↓
    T f(T a, T b) { return (a.first <= b.first) ? a : b; }
    T e() { return make_pair(INT_MAX, -1); }
    // ↑↑↑↑↑ change here! ↑↑↑↑↑
    int n, _n;
    vector<T> dat;
    segtree(int n) : n(n) {
        _n = 1;
        while (_n < n) _n *= 2;
        dat = vector<T>(2 * _n - 1, e());
    }
    void update(int k, T a) {
        k += _n - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = f(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return e();
        if (a <= l && r <= b) return dat[k];
        T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    T query(int a, int b) { return query(a, b, 0, 0, _n); }
};

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int INF = 1 << 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    segtree<pair<int, int>> seg(N + 1);
    rep(i, N) seg.update(i, make_pair(INF, i));
    vector<int> dpf(N + 1, -1);
    seg.update(N, make_pair(0, N));
    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == '1') continue;
        pair<int, int> q = seg.query(i + 1, min(N, i + M) + 1);
        if (q.first == INF) continue;
        dpf[i] = q.second;
        seg.update(i, make_pair(q.first + 1, i));
    }
    if (seg.query(0, 1).first == INF) {
        cout << -1 << '\n';
    } else {
        int c = 0;
        vector<int> ans;
        while (dpf[c] != -1) {
            ans.push_back(dpf[c] - c);
            c = dpf[c];
        }
        rep(i, ans.size()) {
            if (i == 0)
                cout << ans[i];
            else
                cout << " " << ans[i];
        }
        cout << '\n';
    }
    return 0;
}

/**
 * セグメント木
 * 貪欲
 * セグメント木に(値,index)を持たせてdp[i]を更新するときに
 * [i+1,i+M]のdpの最小値とそのときのindex(indexはなるべく左のものを採用)
 * が分かれば解ける
 * が、実は後ろから貪欲に解ける(というか初めて解いたとき貪欲だった)
 * 証明難しめ
 * 注意！：辞書順最小にしたいので、後ろから見て辞書順最大にすればよい
 * は嘘！
 * 参考:https://twitter.com/maspy_stars/status/1198806542230802432
 */
