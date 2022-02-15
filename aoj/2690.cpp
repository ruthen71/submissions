#include <bits/stdc++.h>
using namespace std;
// clang-format off
using ll = long long;
template <class T> using V = vector<T>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
// clang-format on

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, M;
    cin >> N >> M;
    V<V<pair<int, ll>>> G(N);
    rep(i, N - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    V<ll> s(N);
    rep(i, N) cin >> s[i];
    V<ll> vs;
    auto rec = [&](auto self, int cur, int par, int root) -> ll {
        V<ll> ret = {0};
        for (auto &nx : G[cur]) {
            if (nx.first == par) continue;
            ret.push_back(self(self, nx.first, cur, root) + nx.second);
        }
        sort(ALL(ret));
        rep(i, (int)ret.size() - 1) vs.push_back(ret[i] * s[root]);
        return *ret.rbegin();
    };
    rep(v, N) vs.push_back(rec(rec, v, -1, v) * s[v]);
    sort(ALL(vs));
    ll ans = 0;
    while (M-- && vs.size() > 0) {
        ans += *vs.rbegin();
        vs.pop_back();
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 解説AC
 * チームメイトに教えてもらった
 * ラムダ再帰(ポイント：self)
 * HL分解の気持ちになると解けるらしい
 * 結局始点が異なる場合は互いに独立に考えられる
 * 始点を一つ決め、「最長経路を取り、その経路上の点を距離0で行き来できるようにグラフを変形して、再び最長経路を取る…」
 * というのを繰り返し、経路にs[始点]をかけたものを大きい順に貪欲に取れば良い
 * よって各頂点につき、上記の操作がo(N^2)でできればOK
 * これは、「最長経路はいずれも葉から」
 * 「各頂点について、その頂点が初めて経路に使われるのは葉方向の頂点のうち、最も遠い点から来ているとき」
 * 「それ以外の点から来ているときにはその頂点より根の方向の頂点は使われない」
 * あたりを考えると、葉方向からの結果を受け取るDFSで解ける
 */
