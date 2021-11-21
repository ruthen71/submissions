#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    map<ll, ll> dp;
    dp[0] = 0;
    rep(i, n) dp[a[i]] = dp[a[i] - 1] + 1;
    ll arg = 0;
    for (auto p : dp) {
        if (dp[arg] < p.second) arg = p.first;
    }
    ll k = dp[arg];
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (k >= 0 && arg == a[i]) {
            ans.push_back(i + 1);
            k--;
            arg--;
        }
    }
    reverse(ALL(ans));
    cout << SZ(ans) << '\n';
    rep(i, SZ(ans)) {
        if (i != SZ(ans) - 1)
            cout << ans[i] << " ";
        else
            cout << ans[i] << '\n';
    }
    return 0;
}
