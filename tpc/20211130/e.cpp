#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

const int INF = 1 << 30;

void solve(int tt) {
    int n, p, q;
    cin >> n >> p >> q;
    p++, q++;
    int n2 = n * n;
    vector<int> a(p), b(q);
    rep(i, p) cin >> a[i];
    rep(j, q) cin >> b[j];
    rep(i, p) a[i]--;
    rep(j, q) b[j]--;
    vector<int> id(n2, INF);
    rep(i, p) id[a[i]] = i;
    vector<int> b2(q);
    rep(j, q) b2[j] = id[b[j]];
    vector<int> dp(n2, INF);
    rep(i, q) { *lower_bound(ALL(dp), b2[i]) = b2[i]; }
    int ans = lower_bound(ALL(dp), INF) - dp.begin();
    cout << "Case " << tt + 1 << ": " << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve(i);
    return 0;
}

/**
 * LCSと思いきや要素がdistinctなのでLISができる(コンテスト中2回目のLIS)
 * 普通に初見かも
 */