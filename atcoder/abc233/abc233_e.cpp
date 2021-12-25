#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string X;
    cin >> X;
    int n = X.size();
    ll s = 0;  // sum
    rep(i, n) s += X[i] - '0';
    string t = "";
    ll c = 0;  // carry
    rep(i, n) {
        t += '0' + (c + s) % 10;
        c = (c + s) / 10;
        s -= X[n - 1 - i] - '0';
    }
    while (c) {
        t += '0' + c % 10;
        c /= 10;
    }
    reverse(ALL(t));
    cout << t << '\n';
    return 0;
}

/**
 * 別解
 * 桁和をSとして(10X-S)/9らしい
 * すごい
 */
