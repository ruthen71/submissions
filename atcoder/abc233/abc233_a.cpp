#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll X, Y;
    cin >> X >> Y;
    ll rem = max(0ll, Y - X);
    cout << (rem + 9) / 10 << '\n';
    return 0;
}
