#include <bits/stdc++.h>
using namespace std;

#include <atcoder/scc>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) cin >> A[i] >> B[i];
    rep(i, M) A[i]--, B[i]--;
    scc_graph S(N);
    rep(i, M) S.add_edge(A[i], B[i]);
    vector<vector<int>> res = S.scc();
    vector<int> Vs;
    for (auto &resi : res) {
        if (resi.size() >= 2) {
            Vs = resi;
            break;
        }
    }
    if (Vs.size() == 0) return puts("-1") & 0;
    vector<int> exi(N, 0);
    for (auto &vi : Vs) exi[vi] = 1;
    // 頂点集合Vsから誘導部分グラフGを作成
    vector<vector<int>> G(N);
    rep(i, M) if (exi[A[i]] && exi[B[i]]) G[A[i]].push_back(B[i]);
    int s;  // 適当に始点を決める
    rep(i, N) if (exi[i]) s = i;
    while (true) {
        vector<int> from(N, -1), seen(N, 0);
        seen[s] = 1;
        queue<int> que;
        que.push(s);
        vector<int> cycle;
        // 強連結成分内で全域木を作り、始点sに戻ってくる点を探す(それがサイクルになる)
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto &nx : G[v]) {
                if (nx == s) {
                    // 閉路を見つけた
                    cycle.push_back(v);
                    int cur = v;
                    while (cur != s) {
                        cur = from[cur];
                        cycle.push_back(cur);
                    }
                    while (!que.empty()) que.pop();
                    break;
                } else if (seen[nx] == 0) {
                    seen[nx] = 1;
                    from[nx] = v;
                    que.push(nx);
                }
            }
        }
        exi.assign(N, 0);
        for (auto &vi2 : cycle) exi[vi2] = 1;
        // サイクル内に含まれる点で新たな誘導部分グラフを作る
        vector<vector<int>> G2(N);
        rep(i, M) if (exi[A[i]] && exi[B[i]]) G2[A[i]].push_back(B[i]);
        G = G2;
        int ok = 1;
        // 誘導部分グラフの出次数が2以上ならやり直し
        // やり直すときに2以上の点から次BFSをする
        rep(i, N) {
            if (G[i].size() > 1) {
                ok = 0;
                s = i;
                break;
            }
        }
        if (ok) break;
    }
    vector<int> ans;
    rep(i, N) if (exi[i]) ans.push_back(i);
    int K = ans.size();
    cout << K << '\n';
    rep(i, K) {
        if (i == 0)
            cout << ans[i] + 1;
        else
            cout << " " << ans[i] + 1;
    }
    cout << '\n';
    return 0;
}

/**
 * 最小サイクル検出
 * 典型考察:無向グラフの全域木(森)だけ考える
 * 強連結成分を見つけて、サイクルを見つけて
 * サイクルに含まれる点集合で誘導部分グラフを作り
 * というのを繰り返す
 * 0->1->2->3->4->0みたいなサイクルに1->4があったとき
 * 1からBFSすると真に小さいサイクルが見つかる
 * 始点を全探索できるのでそっちのほうが楽そう
 */
