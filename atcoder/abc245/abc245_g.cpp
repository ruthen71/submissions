#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include "debug.hpp"
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T> using V = vector<T>;
template <class T> using pque = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K, L;
    cin >> N >> M >> K >> L;
    V<int> A(N), B(L);
    rep(i, N) {
        cin >> A[i];
        A[i]--;
    }
    rep(i, L) {
        cin >> B[i];
        B[i]--;
    }
    V<int> u(M), v(M);
    V<ll> c(M);
    V<V<pair<int, ll>>> G(N);
    rep(i, M) {
        cin >> u[i] >> v[i] >> c[i];
        u[i]--, v[i]--;
        G[u[i]].push_back({v[i], c[i]});
        G[v[i]].push_back({u[i], c[i]});
    }
    const ll INF = 1LL << 60;
    V<V<ll>> dist(2, V<ll>(N, INF));
    V<V<int>> cid(2, V<int>(N, -1));
    pque<tuple<ll, int, int, int>> que;  // {距離, 頂点番号, dist[0] or dist[1], 始点の国}
    for (auto &bi : B) {
        dist[0][bi] = 0;
        cid[0][bi] = A[bi];
        que.push({0, bi, 0, A[bi]});
    }
    while (!que.empty()) {
        auto [dd, v, id, cc] = que.top();
        que.pop();
        if (dist[id][v] != dd || cid[id][v] != cc) continue;
        for (auto &[nex, cost] : G[v]) {
            if (cid[0][nex] == cc && dist[0][nex] <= dd + cost) continue;
            if (cid[1][nex] == cc && dist[1][nex] <= dd + cost) continue;
            if (dist[0][nex] > dd + cost) {
                if (cid[0][nex] == cc) {
                    dist[0][nex] = dd + cost;
                    que.push({dist[0][nex], nex, 0, cid[0][nex]});
                } else {
                    dist[1][nex] = dist[0][nex];
                    cid[1][nex] = cid[0][nex];
                    que.push({dist[1][nex], nex, 1, cid[1][nex]});
                    dist[0][nex] = dd + cost;
                    cid[0][nex] = cc;
                    que.push({dist[0][nex], nex, 0, cid[0][nex]});
                }
            } else if (dist[1][nex] > dd + cost) {
                dist[1][nex] = dd + cost;
                cid[1][nex] = cc;
                que.push({dist[1][nex], nex, 1, cid[1][nex]});
            }
        }
    }
    rep(i, N) cout << (cid[0][i] != A[i] ? (dist[0][i] != INF ? dist[0][i] : -1) : (dist[1][i] != INF ? dist[1][i] : -1)) << (i == N - 1 ? '\n' : ' ');
    return 0;
}

/**
 * 複数始点Dijkstra法
 * 複数始点最短路問題
 * 上位2つを保持する
 *
 * 上位2つを保持する時の実装のコツ
 * 普通のダイクストラでqueから取り出したときにif(dist[v]<dd)continue;を忘れると最悪計算量が指数時間になる
 * 上位2つの場合にも容易に拡張できる方法について
 * キーアイディア...queに突っ込んだ情報とdist,cidが完全一致しているかで判定
 * (例:if (dist[id][v] != dd || cid[id][v] != cc) continue;の部分)
 * dist(とcid)の更新が起きたら1位->2位の移動だとしても常にqueに入れる(これによってdistとcidが一致する場合がqueに必ず入る)
 * そもそもキューに入れるのは最短路が真に短くなった時のみ(これはまあ、等号の場合を入れてはいけないのはそれはそうなんだけど……)
 * 後は、dist[0]より真に小さい、と、dist[0]以上ではあるがdist[1]よりは真に小さいの2パターンに分ければ良い
 * cid[0]と同じ場合はdist[1]は追い出されないことに注意する
 * cid[0]と異なる場合は普通にdist[1]は追い出される
 */