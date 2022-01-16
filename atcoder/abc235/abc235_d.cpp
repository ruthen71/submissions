#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

ll rot(ll x) {
    string s = to_string(x);
    rotate(s.begin(), s.begin() + s.size() - 1, s.end());
    return stoll(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, N;
    cin >> a >> N;
    map<ll, ll> dp;
    queue<ll> que;
    dp[1] = 1;
    que.push(1);
    while (!que.empty()) {
        ll v = que.front();
        que.pop();
        if (v >= 1000000) continue;
        if (v % 10 != 0) {
            ll n1 = rot(v);
            if (dp[n1] == 0) {
                dp[n1] = dp[v] + 1;
                que.push(n1);
            }
        }
        {
            ll n2 = a * v;
            if (dp[n2] == 0) {
                dp[n2] = dp[v] + 1;
                que.push(n2);
            }
        }
    }
    cout << dp[N] - 1 << '\n';
    return 0;
}

/**
 * BFS
 */