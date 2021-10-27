#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int inf = 1 << 30;

int main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    s--, t--;
    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> dis1(N, inf);
    {
        queue<int> que1;
        que1.push(s);
        dis1[s] = 0;
        while (!que1.empty()) {
            int v = que1.front();
            que1.pop();
            for (auto &e : g[v]) {
                if (dis1[e] > dis1[v] + 1) {
                    dis1[e] = dis1[v] + 1;
                    que1.push(e);
                }
            }
        }
    }

    vector<int> dis2(N, inf);
    {
        queue<int> que2;
        que2.push(t);
        dis2[t] = 0;
        while (!que2.empty()) {
            int v = que2.front();
            que2.pop();
            for (auto &e : g[v]) {
                if (dis2[e] > dis2[v] + 1) {
                    dis2[e] = dis2[v] + 1;
                    que2.push(e);
                }
            }
        }
    }
    vector<int> c(N, 0);
    for (int i = 0; i < N; i++) {
        if (dis2[i] != inf) c[dis2[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (dis1[t] - 2 - dis1[i] >= 0) ans += c[dis1[t] - 2 - dis1[i]];
    }
    cout << ans << endl;
}

/*
sからの距離dis1とtからの距離dis2をBFSで前計算
dis1[u]+2+dis2[v]==dis1[t]
となるu,vの個数
dis2[v]の値ごとに対応するvがいくつあるか求めておく
オーバーフローに注意
*/
