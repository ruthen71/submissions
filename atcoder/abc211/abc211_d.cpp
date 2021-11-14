#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)

ll mod = 1000000007;
ll INF = 1ll << 60;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> dist(N, INF), ans(N, 0);
    dist[0] = 0;
    ans[0] = 1;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int &nx : g[v]) {
            if (dist[nx] > dist[v] + 1) {
                dist[nx] = dist[v] + 1;
                ans[nx] = ans[v];
                que.push(nx);
            } else if (dist[nx] == dist[v] + 1) {
                ans[nx] = (ans[nx] + ans[v]) % mod;
            }
        }
    }
    cout << ans[N - 1] << endl;
    return 0;
}
