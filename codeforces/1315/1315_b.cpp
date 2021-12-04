#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

void solve() {
    ll a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    int n = s.size();
    s = "0" + s;
    int ok = n, ng = 0;
    while (ok - ng > 1) {
        int md = (ok + ng) / 2;
        ll c = (s[md] == 'A') ? a : b;
        for (int i = md + 1; i < n; i++) {
            if (s[i] != s[i - 1]) c += (s[i] == 'A') ? a : b;
        }
        if (c <= p)
            ok = md;
        else
            ng = md;
    }
    cout << ok << '\n';
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

/**
 * 二分探索したけど普通に後ろからやっても良い
 */