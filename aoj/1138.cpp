#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll INF = 1ll << 60;

void solve(ll n) {
    ll m, p, a, b;
    cin >> m >> p >> a >> b;
    a--, b--;
    vector<ll> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    ll n2 = (1 << n);
    ll V = n2 * m;
    vector<vector<pair<ll, ll>>> g(m);
    for (int i = 0; i < p; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    vector<ld> dist(V, INF);
    dist[a * n2] = 0;
    priority_queue<pair<ld, ll>, vector<pair<ld, ll>>, greater<pair<ld, ll>>> pq;
    pq.push({0, a * n2});
    while (!pq.empty()) {
        ll v = pq.top().second, d = pq.top().first;
        pq.pop();
        ll idx = v / n2, bit = v % n2;
        for (auto &e : g[idx]) {
            for (int i = 0; i < n; i++) {
                if (bit >> i & 1) continue;
                ld cost = (ld)e.second / t[i];
                ll nx = (e.first * n2) + (bit | (1 << i));
                if (dist[nx] > dist[v] + cost) {
                    dist[nx] = dist[v] + cost;
                    pq.push({dist[nx], nx});
                }
            }
        }
    }
    ld ans = INF;
    for (int bit = 0; bit < n2; bit++) {
        ans = min(ans, dist[b * n2 + bit]);
    }
    if (ans == INF)
        puts("Impossible");
    else
        printf("%.15Lf\n", ans);
    return;
}

int main() {
    ll n;
    while (cin >> n, n) solve(n);
    return 0;
}

/*
bitDP+ダイクストラ
現在使ったチケットをbitで持ちつつダイクストラをする

*/
