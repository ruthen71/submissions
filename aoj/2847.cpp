#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
// clang-format off
template <class T> using V = vector<T>;
// clang-format on

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int N2 = N * N;
    V<V<int>> G(N2);
    rep(i, 2 * N * (N - 1)) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    V<int> used(N2, 0);
    V<V<int>> ans(N, V<int>(N, -1));
    int s = -1;
    rep(i, N2) {
        if (G[i].size() == 2) {
            s = i;
            break;
        }
    }
    ans[0][0] = s;
    used[s] = 1;
    {
        int v = G[s][0], i = 0, j = 1;
        ans[i][j++] = v;
        used[v] = 1;
        while (G[v].size() != 2) {
            int nx = -1;
            for (auto &gi : G[v]) {
                if (G[gi].size() <= 3 && used[gi] == 0) {
                    nx = gi;
                    break;
                }
            }
            v = nx;
            ans[i][j++] = v;
            used[v] = 1;
        }
    }
    {
        int v = G[s][1], i = 1, j = 0;
        ans[i++][j] = v;
        used[v] = 1;
        while (G[v].size() != 2) {
            int nx = -1;
            for (auto &gi : G[v]) {
                if (G[gi].size() <= 3 && used[gi] == 0) {
                    nx = gi;
                    break;
                }
            }
            v = nx;
            ans[i++][j] = v;
            used[v] = 1;
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            int v1 = ans[i - 1][j], v2 = ans[i][j - 1];
            int nx = -1;
            for (auto &nx1 : G[v1]) {
                for (auto &nx2 : G[v2]) {
                    if (nx1 == nx2 && used[nx1] == 0) {
                        nx = nx1;
                    }
                }
            }
            ans[i][j] = nx;
            used[nx] = 1;
        }
    }
    rep(i, N) rep(j, N) cout << ans[i][j] + 1 << (j == N - 1 ? '\n' : ' ');
    return 0;
}

/**
 * グリッドグラフに埋め込む
 */
