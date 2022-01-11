#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const ll INF = 1ll << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> P(N);
    rep(i, N) cin >> P[i];
    map<ll, vector<ll>> mp;
    mp[P[0]].push_back(0);
    vector<vector<int>> G(N);
    for (int i = 1; i < N; i++) {
        for (auto &nx : mp[i - P[i]]) {
            G[i].push_back(nx);
            G[nx].push_back(i);
        }
        mp[P[i] + i].push_back(i);
    }
    queue<int> que;
    vector<ll> dist(N, INF);
    dist[0] = 0;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto &nx : G[v]) {
            if (dist[nx] != INF) continue;
            dist[nx] = dist[v] + 1;
            que.push(nx);
        }
    }
    int ans = 0;
    rep(i, N) if (dist[i] != INF) ans = i;
    cout << ans << '\n';
    return 0;
}

/**
 * Zero-Sum Ranges系
 * 全ての(i,j)のペアについて、iとjは行き来可能かについて考えるとTLEする
 * しかしpairの数は10^6個以下であると保証されている
 * i<jとしてP[i]+P[j]=j-iより
 * P[i]+i=j-P[j]
 * mapに保存
 * よってこれでグラフが構築できたので、BFSする
 */
