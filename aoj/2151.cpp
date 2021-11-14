#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll INF = 1ll << 60;

struct edge {
    ll to, d, e;
};

void solve(ll n) {
    ll M, L;
    cin >> M >> L;
    vector<vector<edge>> g(n);
    for (int i = 0; i < M; i++) {
        ll a, b, D, E;
        cin >> a >> b >> D >> E;
        a--, b--;
        g[a].push_back({b, D, E});
        g[b].push_back({a, D, E});
    }
    ll L1 = L + 1;
    vector<vector<ll>> dp(n, vector<ll>(L1, INF));
    dp[0][L] = 0;
    ll V = n * L1;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, L});
    while (!pq.empty()) {
        ll v = pq.top().second, d = pq.top().first;
        pq.pop();
        ll cn = v / L1, cl = v % L1;
        if (dp[cn][cl] < d) continue;
        for (auto &e : g[cn]) {
            // お金を使う場合
            if (cl >= e.d) {
                ll nex = e.to * L1 + cl - e.d;
                if (dp[e.to][cl - e.d] > dp[cn][cl]) {
                    dp[e.to][cl - e.d] = dp[cn][cl];
                    pq.push({dp[e.to][cl - e.d], nex});
                }
            }
            // お金を使わない場合
            ll nex2 = e.to * L1 + cl;
            if (dp[e.to][cl] > dp[cn][cl] + e.e) {
                dp[e.to][cl] = dp[cn][cl] + e.e;
                pq.push({dp[e.to][cl], nex2});
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i <= L; i++) ans = min(ans, dp[n - 1][i]);
    cout << ans << endl;
    return;
}

int main() {
    ll n;
    while (cin >> n, n) solve(n);
    return 0;
}

/*
現在いる頂点と所持金を状態として持ちながらダイクストラする
*/
