#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

ll INF = 1ll << 60;

template <class T>
struct fenwick_tree {
    int N;
    vector<T> seg;
    fenwick_tree(int N) : N(N), seg(N + 1, 0) {}
    // i番目の要素にxを加算する
    void add(int i, T x) {
        i++;  // 1-indexedにする
        while (i <= N) {
            seg[i] += x;
            i += i & -i;
        }
    }
    // 区間[0, i)の和!!
    // iを含まないことに注意!!
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }
    // 区間[a, b)の和
    T sum(int a, int b) { return sum(b) - sum(a); }
};

int main() {
    ll H, W, M;
    cin >> H >> W >> M;
    vector<ll> x(M), y(M);
    rep(i, M) cin >> x[i] >> y[i];
    rep(i, M) x[i]--, y[i]--;
    vector<ll> a(H, W), b(W, H);
    ll mh = H, mw = W;
    rep(i, M) {
        a[x[i]] = min(a[x[i]], y[i]);
        b[y[i]] = min(b[y[i]], x[i]);
        if (x[i] == 0) mw = min(mw, y[i]);
        if (y[i] == 0) mh = min(mh, x[i]);
    }
    ll ans = 0;
    for (int i = 0; i < mh; i++) ans += a[i];
    for (int j = 0; j < mw; j++) ans += b[j];
    vector<vector<ll>> g(H);
    rep(i, M) g[x[i]].push_back(y[i]);
    fenwick_tree<ll> fw(W);
    rep(i, W) fw.add(i, 1);
    for (int i = 0; i < mh; i++) {
        ll ub = mw;
        for (auto yi : g[i]) {
            ub = min(ub, yi);
        }
        ans -= fw.sum(ub);
        for (auto yi : g[i]) {
            if (fw.sum(yi, yi + 1) == 1) fw.add(yi, -1);
        }
    }
    cout << ans << '\n';
    return 0;
}

/*
BIT
Fenwick Tree
フェニック木
包除原理
まず、O(HW)は無理なので、重複も含めてならO(W+H)で
求められることを考える
重複分の数え方だが、片方の軸に沿って平面走査し、BITで現在の個数を持っておくイメージ
ABC211-Fと似ている(というか、O(HW)が間に合わない時だいたい平面走査するイメージがある)
*/