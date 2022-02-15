#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
// clang-format off
template <class T> using V = vector<T>;
// clang-format on
const ll INF = 1ll << 60;
using ld = double;

template <class T>
T cost(ll t, ll C, ll D, T x) {
    return x + C + D / (1 + t + x);
}

ll calc(ll T, ll C, ll D) {
    ld lb = 0, ub = INF;
    rep(tt, 100) {
        ld d = ub - lb;
        ld l = lb + d / 3, r = lb + 2 * d / 3;
        if (cost(T, C, D, l) > cost(T, C, D, r))
            lb = l;
        else
            ub = r;
    }
    ll retx = (ll)lb;
    for (int k = -2; k <= 2; k++) {
        ll x = lb + k;
        if (x < 0) continue;
        if (cost(T, C, D, x) < cost(T, C, D, retx)) retx = x;
    }
    return cost(T, C, D, retx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    V<ll> A(M), B(M), C(M), D(M);
    V<V<pair<int, int>>> G(N);
    rep(i, M) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        A[i]--, B[i]--;
        G[A[i]].push_back({B[i], i});
        G[B[i]].push_back({A[i], i});
    }
    V<ll> dist(N, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.push({0, 0});
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (auto &es : G[v]) {
            ll cost = calc(dist[v], C[es.second], D[es.second]);
            if (dist[es.first] > dist[v] + cost) {
                dist[es.first] = dist[v] + cost;
                que.push({dist[es.first], es.first});
            }
        }
    }
    cout << (dist[N - 1] == INF ? -1 : dist[N - 1]) << '\n';
    return 0;
}

/**
 * 三分探索
 * コストの最小値を三分探索で求める
 * 整数の三分探索だと広義凸なのでダメ
 * floorを抜いた関数に対してコストを求めて近傍を探索する
 * floorをとってもa<b->floor(a)<=floor(b)なので
 */
