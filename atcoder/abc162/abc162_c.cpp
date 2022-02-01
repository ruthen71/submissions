#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll K;
    cin >> K;
    ll s = 0;
    for (ll a = 1; a <= K; a++)
        for (ll b = 1; b <= K; b++)
            for (ll c = 1; c <= K; c++) s += gcd(gcd(a, b), c);
    cout << s << '\n';
    return 0;
}

/**
 * gcdはlog(最大値)で求められるので愚直にやる
 */
