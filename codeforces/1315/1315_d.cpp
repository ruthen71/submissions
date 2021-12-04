#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

multiset<ll> S[200005];

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> t(n);
    rep(i, n) cin >> t[i];
    vector<ll> za = a;
    sort(ALL(za));
    za.erase(unique(ALL(za)), za.end());
    rep(i, n) a[i] = lower_bound(ALL(za), a[i]) - za.begin();
    rep(i, n) S[a[i]].insert(-t[i]);
    ll ans = 0;
    multiset<pair<ll, ll>> ms;
    ll last = 0;
    rep(i, za.size()) {
        if (i != 0) {
            ll t = min(za[i] - last, (ll)ms.size());
            rep(j, t) {
                auto itr = ms.begin();
                pair<ll, ll> ps = (*itr);
                ans += -ps.first * (last + j - ps.second);
                ms.erase(itr);
            }
        }
        last = za[i];
        for (auto si : S[i]) ms.insert({si, za[i]});
    }
    while (ms.size()) {
        auto itr = ms.begin();
        pair<ll, ll> ps = (*itr);
        ans += -ps.first * (last - ps.second);
        ms.erase(itr);
        last++;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * map,set系
 */