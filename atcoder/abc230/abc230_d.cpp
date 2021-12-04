#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ll N, D;
    cin >> N >> D;
    vector<pair<ll, ll>> LR(N);
    rep(i, N) cin >> LR[i].second >> LR[i].first;
    sort(ALL(LR));
    ll R = 0, ans = 0;
    rep(i, N) {
        if (LR[i].second <= R) continue;
        ans++;
        R = max(R, LR[i].first + D - 1);
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 区間スケジューリング問題と同じ
 * 右端でソートする
 */