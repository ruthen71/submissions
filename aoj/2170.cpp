#include <bits/stdc++.h>
using namespace std;

#include <atcoder/lazysegtree>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int INF = 1 << 30;

void dfs(vector<vector<int>> &G, vector<int> &P, vector<int> &depth, int &cnt, int cur, int par) {
    P[cnt++] = cur;
    for (auto &nx : G[cur]) {
        if (nx != par) {
            depth[nx] = depth[cur] + 1;
            dfs(G, P, depth, cnt, nx, cur);
            P[cnt++] = cur;
        }
    }
    return;
}

using S = pair<int, int>;
using F = pair<int, int>;

S op(S a, S b) { return max(a, b); }
S e() { return {0, 0}; }
F id() { return {-INF, 0}; }
S mapping(F f, S x) { return (f == id() ? x : max(f, x)); }
F composition(F f, F g) { return (f == id() ? g : max(f, g)); }

void solve(int N, int Q) {
    vector<vector<int>> G(N);
    rep(i, N - 1) {
        int v;
        cin >> v;
        v--;
        G[i + 1].push_back(v);
        G[v].push_back(i + 1);
    }
    vector<int> P(2 * N - 1, -1), depth(N);
    int cnt = 0;
    depth[0] = 0;
    dfs(G, P, depth, cnt, 0, -1);
    assert(cnt == 2 * N - 1);
    vector<int> L(N, INF), R(N, -INF);
    rep(i, 2 * N - 1) {
        L[P[i]] = min(L[P[i]], i);
        R[P[i]] = max(R[P[i]], i);
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(2 * N - 1);
    ll ans = 0;
    while (Q--) {
        char type;
        int v;
        cin >> type >> v;
        v--;
        if (type == 'M') {
            seg.apply(L[v], R[v] + 1, make_pair(depth[v], v));
        } else {
            ans += seg.get(L[v]).second + 1;
        }
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    while (cin >> N >> Q, N != 0 && Q != 0) solve(N, Q);
    return 0;
}

/**
 * DFS
 * Lazy Segment Tree(区間更新区間最大値)
 * DFSの訪問順に頂点を並べる
 * 並べた頂点をPとする
 * ans[P[i]]=頂点P[i]に対応する答え
 * とすると、頂点vに色を塗ると、Pにおいて最も左側のvと最も右側のvの「間にある頂点全て」
 * に影響を与える
 * よってこれらの頂点について「vを考慮してね」という情報を遅延セグメント木で一気に伝える
 */
