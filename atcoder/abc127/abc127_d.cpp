#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M), C(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i] >> C[i];
    map<ll, int> mp;
    rep(i, N) mp[A[i]]++;
    rep(i, M) mp[C[i]] += B[i];
    vector<pair<ll, int>> cnt;
    for (auto &p : mp) cnt.push_back(p);
    int sz = cnt.size();
    ll ans = 0;
    for (int i = sz - 1; i >= 0; i--) {
        ans += cnt[i].first * min(N, cnt[i].second);
        N -= min(N, cnt[i].second);
    }
    cout << ans << '\n';
    return 0;
}
