#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll f(ll x, ll c, ll d) {
    ll g = lcm(c, d);
    return x - (x / c + x / d - x / g);
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = f(b, c, d) - f(a - 1, c, d);
    cout << ans << '\n';
    return 0;
}
