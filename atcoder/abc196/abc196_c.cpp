#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    for (ll i = 1; i <= 1000000; i++) {
        string s = to_string(i);
        string u = s + s;
        ll x = stoll(u);
        // cout << x << '\n';
        if (x <= N) ans++;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 文字列->数値:stoll(stoi)
 * 数値->文字列:to_string
 */