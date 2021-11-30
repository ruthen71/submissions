#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> mov(m, n / m);
    vector<int> ok(n, 1);
    vector<pair<ll, int>> id;
    rep(i, n) {
        if (mov[a[i] % m] > 0) {
            mov[a[i] % m]--;
            continue;
        }
        ok[i] = 0;
        id.push_back({a[i] % m, i});
    }
    sort(ALL(id));
    multiset<ll> s;
    rep(i, m) rep(j, mov[i]) s.insert(i);
    int n2 = SZ(id);
    ll ans = 0;
    vector<ll> ansv(n);
    rep(i, n) if (ok[i]) ansv[i] = a[i];
    rep(i, n2) {
        auto itr = s.lower_bound(id[i].first);
        if (itr == s.end()) {
            itr = s.lower_bound(0);
        }
        ll c = (*itr) - id[i].first;
        if (c < 0) c += m;
        assert(0 <= c && c < m);
        ans += c;
        ansv[id[i].second] = a[id[i].second] + c;
        s.erase(itr);
    }
    cout << ans << '\n';
    rep(i, n) {
        if (i == 0)
            cout << ansv[i];
        else
            cout << " " << ansv[i];
    }
    cout << '\n';
    return 0;
}

/**
 * multisetを使う
 * 以下modMで考える
 * 余分にある要素を、そこから+1足す回数が最も少なくてかつ不足しているところに移動させる
 * n/m個以上ある要素は、不足している部分でもっとも近いところに持って行くイメージ
 * 開始後しばらくこの操作が、「不足分と余計分をそれぞれソートして
 * 小さい順に突き合わせる」で良いと思っていた
 * （余計分の最小値より小さい不足分にはmを加算する、でもダメ）
 */