#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) begin(x), end(x)
template <class T> using V = vector<T>;

#include <atcoder/dsu>
using namespace atcoder;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    V<ll> D(N);
    rep(i, N) cin >> D[i];
    if (accumulate(ALL(D), 0LL) != 2 * (N - 1)) {
        cout << -1 << '\n';
        return 0;
    }
    V<int> u(M), v(M);
    dsu uf(N);
    int ss = N;
    rep(i, M) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        D[u[i]]--, D[v[i]]--;
        if (uf.same(u[i], v[i])) {
            cout << -1 << '\n';
            return 0;
        }
        uf.merge(u[i], v[i]);
        ss--;
    }
    V<V<int>> G2(N);
    rep(i, N) {
        if (D[i] < 0) {
            cout << -1 << '\n';
            return 0;
        }
        rep(j, D[i]) G2[uf.leader(i)].push_back(i);
    }
    assert(ss - 1 == N - 1 - M);
    priority_queue<pair<int, int>> pq;
    rep(i, N) {
        if (G2[i].size() > ss - 1) {
            cout << -1 << '\n';
            return 0;
        }
        if (G2[i].size() > 0) pq.push({G2[i].size(), i});
    }
    V<int> ans1(N - 1 - M, -1), ans2(N - 1 - M, -1);
    rep(i, N - 1 - M) {
        if (pq.size() < 2) {
            cout << -1 << '\n';
            return 0;
        }
        auto p1 = pq.top();
        pq.pop();
        auto p2 = pq.top();
        pq.pop();
        ans1[i] = G2[p1.second].back();
        G2[p1.second].pop_back();
        ans2[i] = G2[p2.second].back();
        G2[p2.second].pop_back();
        if (G2[p1.second].size() > G2[p2.second].size()) swap(p1, p2);
        for (auto &v : G2[p1.second]) G2[p2.second].push_back(v);
        if (p1.first + p2.first - 2 > 0) pq.push({p1.first + p2.first - 2, p2.second});
    }
    rep(i, N - 1 - M) cout << ans1[i] + 1 << ' ' << ans2[i] + 1 << '\n';
    return 0;
}

/**
 * マージテク
 * まずあらかじめ与えられている辺の情報から連結成分ごとにまとめておく
 * 連結成分として次数が大きい順にマージする
 * マージした後、マージテクを使って、次数が小さいほうから大きいほうに繋ぐべき点を移動させるとO(NlogN)でできる
 */