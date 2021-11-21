#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

const ll INF = 1ll << 60;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(ALL(a));
    if (k == 0) {
        if (a[0] != 1) {
            cout << 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return 0;
    }
    if (a[k - 1] != a[k])
        cout << a[k - 1] << '\n';
    else
        cout << -1 << '\n';
    return 0;
}
