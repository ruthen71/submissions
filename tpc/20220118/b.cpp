#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const ll INF = 1ll << 60;

map<string, ll> mp;

int rec(string S) {
    if (mp[S] != 0) return mp[S];
    int ret = 1;
    int n = S.size();
    rep(i, n - 2) {
        if (S.substr(i, 3) == "-oo") {
            S[i] = 'o';
            S[i + 1] = S[i + 2] = '-';
            ret = max(ret, rec(S) + 1);
            S[i] = '-';
            S[i + 1] = S[i + 2] = 'o';
        }
        if (S.substr(i, 3) == "oo-") {
            S[i] = S[i + 1] = '-';
            S[i + 2] = 'o';
            ret = max(ret, rec(S) + 1);
            S[i] = S[i + 1] = 'o';
            S[i + 2] = '-';
        }
    }
    return mp[S] = ret;
}

void solve() {
    string S;
    cin >> S;
    int ans = 0;
    for (auto c : S) {
        if (c == 'o') ans++;
    }
    cout << ans - (rec(S) - 1) << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}

/**
 * oo- -> --o
 * -oo -> o--
 * のどちらかの操作を行いながら
 * 適当にメモ化再帰する
 */
