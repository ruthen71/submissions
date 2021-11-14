#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll INF = 1ll << 60;

int main() {
    ll W;
    cin >> W;
    vector<ll> a(W);
    for (int i = 0; i < W; i++) cin >> a[i];
    vector<ll> dp1(W, INF);
    ll c = 0;
    for (int i = W - 1; i >= 0; i--) {
        if (a[i] == 0) c = INF;
        if (a[i] < 0) c = min(-a[i], c);
        dp1[i] = c--;
    }
    vector<ll> dp2(W, INF);
    c = 0;
    for (int i = 0; i < W; i++) {
        if (a[i] == 0) c = INF;
        if (a[i] < 0) c = min(-a[i], c);
        dp2[i] = c--;
    }
    ll ans = 0;
    for (int i = 0; i < W; i++) {
        ans += max(0ll, min(a[i], max(dp1[i], dp2[i])));
    }
    cout << ans << endl;
    return 0;
}

/*
各マスの乗客は右から逃げるか左から逃げるかしかない
dp[i]=マスiにいる乗客が何人抜けられるか
を右と左でやる
*/