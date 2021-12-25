#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, X;
    cin >> N >> X;
    map<ll, ll> mp;
    mp[X] = 1;
    rep(i, N) {
        ll L;
        cin >> L;
        vector<ll> a(L);
        rep(j, L) cin >> a[j];
        map<ll, ll> A;
        rep(j, L) A[a[j]]++;
        map<ll, ll> mp2;
        for (auto p : mp) {
            for (auto ai : A) {
                if (p.first % ai.first != 0) continue;
                mp2[p.first / ai.first] += p.second * ai.second;
            }
        }
        mp = mp2;
    }
    cout << mp[1] << '\n';
    return 0;
}

/**
 * 「総積」（総和ではなく）が10^5以下なので、DFSすればよかったらしい
 * mapでいろいろやった
 */
