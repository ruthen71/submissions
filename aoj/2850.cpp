#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
const int INF = 1 << 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> diso(N, INF), dise(N, INF);
    dise[0] = 0;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        if (dise[v] != INF) {
            for (auto &nx : G[v]) {
                if (diso[nx] == INF) {
                    diso[nx] = dise[v] + 1;
                    que.push(nx);
                }
            }
        }
        if (diso[v] != INF) {
            for (auto &nx : G[v]) {
                if (dise[nx] == INF) {
                    dise[nx] = diso[v] + 1;
                    que.push(nx);
                }
            }
        }
    }
    int em = 0, om = 0;
    rep(i, N) {
        em = max(em, dise[i]);
        om = max(om, diso[i]);
    }
    int ans = min(em, om);
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}

/**
 * 二部グラフ判定で-1かはわかる
 * 二部グラフではない<=>サイクルがある
 * -1じゃないときについてだが、ある点が集合に追加されているとき、グラフが連結なので
 * 2回後の集合にもその頂点は入っている
 * よって集合のサイズは単調増加する
 * よって奇数回で行ける点集合と偶数回で行ける点集合をそれぞれ求めれば良い
 * これはdist_e, dist_oを持っておけば良い
 */
