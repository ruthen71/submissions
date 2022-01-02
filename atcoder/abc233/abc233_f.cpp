#include <bits/stdc++.h>
using namespace std;

#include <atcoder/dsu>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int INF = 1 << 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i, N) cin >> P[i];
    int M;
    cin >> M;
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];
    rep(i, N) P[i]--;
    rep(i, M) A[i]--, B[i]--;
    dsu uf(N);
    rep(i, M) uf.merge(A[i], B[i]);
    int ok = 1;
    rep(i, N) if (!uf.same(i, P[i])) ok = 0;
    if (ok == 0) return puts("-1") & 0;
    vector<vector<int>> e_id(N, vector<int>(N, -1));  // 辺->id
    rep(i, M) {
        e_id[A[i]][B[i]] = i;
        e_id[B[i]][A[i]] = i;
    }
    vector<vector<int>> es(N);  // 属する成分->辺のid
    rep(i, M) es[uf.leader(A[i])].push_back(i);
    vector<int> seen(N, 0);
    vector<int> ans;
    rep(i, N) {
        if (uf.leader(i) != i) continue;
        int N2 = uf.size(i);
        vector<int> seen(N, 0);
        // 連結成分ごとにグラフを構築
        dsu uf2(N);
        vector<vector<int>> g(N);
        set<int> S;
        for (auto &e : es[i]) {
            if (!uf2.same(A[e], B[e])) {
                // 全域木に必要な辺のみ追加(1600ms->60ms)
                g[A[e]].push_back(B[e]);
                g[B[e]].push_back(A[e]);
                uf2.merge(A[e], B[e]);
                S.insert(A[e]);
                S.insert(B[e]);
            }
        }
        while (N2--) {
            // BFS
            int s = *S.begin();
            assert(s != -1);
            queue<int> que;
            que.push(s);
            int last = -1;
            vector<int> vis(N, 0);
            while (!que.empty()) {
                int cur = que.front();
                que.pop();
                if (vis[cur] || seen[cur]) continue;
                vis[cur] = 1;
                last = cur;
                for (auto &nx : g[cur]) {
                    if (vis[nx] || seen[cur]) continue;
                    que.push(nx);
                }
            }
            assert(last != -1);
            int s2 = -1;
            rep(i, N) if (P[i] == last) {
                s2 = i;
                break;
            }
            assert(s2 != -1);
            vector<int> dis(N, INF), cfro(N, -1);
            dis[last] = 0;
            que.push(last);
            while (!que.empty()) {
                int cur = que.front();
                que.pop();
                if (seen[cur]) continue;
                for (auto &nx : g[cur]) {
                    if (dis[nx] != INF || seen[cur]) continue;
                    dis[nx] = dis[cur] + 1;
                    cfro[nx] = cur;
                    que.push(nx);
                }
            }
            while (s2 != last) {
                ans.push_back(e_id[s2][cfro[s2]]);
                swap(P[s2], P[cfro[s2]]);
                s2 = cfro[s2];
            }
            seen[last] = 1;
            S.erase(last);
        }
    }
    cout << ans.size() << '\n';
    rep(i, (int)ans.size()) {
        if (i == 0)
            cout << ans[i] + 1;
        else
            cout << " " << ans[i] + 1;
    }
    cout << '\n';
    return 0;
}

/**
 * DSU(UnionFind)で可能か判定
 * できる場合は葉から順番にやる
 * 重実装
 */
