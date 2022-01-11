#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

ll gcd(ll A, ll B) { return B ? gcd(B, A % B) : A; }
ll lcm(ll A, ll B) { return A / gcd(A, B) * B; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll A, B;
    cin >> A >> B;
    cout << lcm(A, B) << '\n';
    return 0;
}
