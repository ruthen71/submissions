#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> dp(n, INF);
    rep(i, n) { *lower_bound(ALL(dp), a[i]) = a[i]; }
    int ans = lower_bound(ALL(dp), INF) - dp.begin();
    cout << ans << '\n';
    return 0;
}

/**
 * なんかLISを書いたら通った(え？)
 * 転倒しなければ良いのでLIS
 */