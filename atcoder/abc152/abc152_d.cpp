#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
ll c[10][10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    cin >> N;
    for (int x = 1; x <= N; x++) {
        c[x % 10][to_string(x)[0] - '0']++;
    }
    ll ans = 0;
    rep(i, 10) rep(j, 10) ans += c[i][j] * c[j][i];
    cout << ans << '\n';
    return 0;
}

/**
 * あらかじめ先頭がiで末尾が0である個数をc[i][j]に記録しておく
 */