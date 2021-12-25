#include <bits/stdc++.h>
using namespace std;

struct lowest_common_ancestor {
    vector<vector<int>> G;
    vector<int> depth;
    vector<vector<int>> parent;
    int n, LOG;  // n = 頂点数, root = 根とする頂点番号, LOG = ダブリングする深さ
    lowest_common_ancestor(int n) : n(n), LOG(32 - __builtin_clz(n)), G(n) {}
    void add_edge(int u, int v) {
        // 無向辺{u, v}を加える
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void build(int root = 0) {
        depth.assign(n, 0);
        parent.assign(LOG, vector<int>(n, 0));
        dfs(root, -1, 0);
        for (int k = 0; k + 1 < LOG; k++) {
            for (int v = 0; v < n; v++) {
                if (parent[k][v] < 0)
                    parent[k + 1][v] = -1;
                else
                    parent[k + 1][v] = parent[k][parent[k][v]];
            }
        }
    }
    void dfs(int cur, int par, int d) {
        parent[0][cur] = par;
        depth[cur] = d;
        for (auto &nx : G[cur]) {
            if (nx != par) dfs(nx, cur, d + 1);
        }
    }
    int lca(int u, int v) {
        assert((int)depth.size() == n);
        if (depth[u] > depth[v]) swap(u, v);
        // depth[u] <= depth[v](vの方が深い)
        // 同じ深さまでvが登る
        for (int k = 0; k < LOG; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;
        for (int k = LOG - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

struct edge {
    int to;
    ll cost;
    int c;
};

int N, Q;
const int V = 100005;
vector<edge> g[V];
vector<pair<int, ll>> cl[V], dl[V];
int id[V], vlist[2 * V], cum[2 * V + 1];

void dfs(int cur, int par, int &ind) {
    id[cur] = ind;
    vlist[ind++] = cur;
    for (auto &es : g[cur]) {
        if (es.to != par) {
            cum[ind] = cum[ind - 1] + es.cost;
            cl[es.c].push_back({ind, (cl[es.c].end() - 1)->second + es.cost});
            dl[es.c].push_back({ind, (dl[es.c].end() - 1)->second + 1});
            dfs(es.to, cur, ind);
            cum[ind] = cum[ind - 1] - es.cost;
            cl[es.c].push_back({ind, (cl[es.c].end() - 1)->second - es.cost});
            dl[es.c].push_back({ind, (dl[es.c].end() - 1)->second - 1});
            vlist[ind++] = cur;
        }
    }
    return;
}

const ll INF = 1ll << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q;
    lowest_common_ancestor lca(N);
    rep(i, N - 1) {
        int a, b, c;
        ll d;
        cin >> a >> b >> c >> d;
        a--, b--, c--;
        g[a].push_back((edge){b, d, c});
        g[b].push_back((edge){a, d, c});
        lca.add_edge(a, b);
    }
    rep(i, N - 1) cl[i].push_back({0, 0});  //番兵
    rep(i, N - 1) dl[i].push_back({0, 0});  //番兵
    int ind = 0;
    dfs(0, -1, ind);
    lca.build();
    rep(i, Q) {
        int x, u, v;
        ll y;
        cin >> x >> y >> u >> v;
        x--, u--, v--;
        int l = lca.lca(u, v);
        ll ret = cum[id[u]] - 2 * cum[id[l]] + cum[id[v]];
        ret -= ((lower_bound(ALL(cl[x]), make_pair(id[u], INF)) - 1)->second);
        ret -= ((lower_bound(ALL(cl[x]), make_pair(id[v], INF)) - 1)->second);
        ret += ((lower_bound(ALL(cl[x]), make_pair(id[l], INF)) - 1)->second) * 2;
        ret += ((lower_bound(ALL(dl[x]), make_pair(id[u], INF)) - 1)->second) * y;
        ret += ((lower_bound(ALL(dl[x]), make_pair(id[v], INF)) - 1)->second) * y;
        ret -= ((lower_bound(ALL(dl[x]), make_pair(id[l], INF)) - 1)->second) * 2 * y;
        cout << ret << '\n';
    }
    return 0;
}

/**
 * 解説AC
 * HL分解？で殴れるらしい
 * ↑木のパスに関するクエリを解くときに強いらしい
 * Wavelet Matrix でも殴れる？（これは本当かわからない）
 * LCA
 * オイラーツアー
 * 重実装
 * 蟻本に変更する辺の本数が1本の場合が書いてあり、「複数辺更新の場合はどうすれば…」となって終了
 * ↑複数辺更新とは言っても次のクエリでは変更が元に戻るのでちょっと違った
 * (辺更新を引き継がないという条件を上手く使う)
 * まず重み更新がない場合を考える
 * LCAを求めて、
 * 葉に進むときに+重み、戻るときに-重みとして考えた配列において
 * 累積和を計算することで求められる(蟻本のp295のAに相当)
 * 実際にはu-vのパス上の色xの重みの総和を引いて、色xの辺の本数*yを足す必要がある
 * 色ごとに上記の累積和を持つとMLEする(色数(N-1)*配列サイズ(2N-1)なので当然)
 * メモリを削減するために…
 * 「色ごとに」「変わるタイミングだけ」持ってpair(ind, cum_x[i])みたいなものを持つ
 * その上で二分探索する
 *
 */
