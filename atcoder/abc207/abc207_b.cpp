#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c * d - b <= 0) {
        cout << -1 << endl;
    } else {
        cout << (a + c * d - b - 1) / (c * d - b) << endl;
    }
    return 0;
}
