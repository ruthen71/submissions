#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, n) cin >> b[i];
    int n2 = n * 2;
    vector<int> c(n2 + 1, 1);
    rep(i, n) c[b[i]] = 0;
    vector<int> d;
    rep(i, n2) if (c[i + 1]) d.push_back(i + 1);
    vector<int> id(n2 + 1, -1);
    rep(i, n) id[b[i]] = 2 * i;
    vector<int> b2 = b;
    sort(ALL(b));
    rep(i, n) if (d[i] < b[i]) {
        cout << -1 << '\n';
        return;
    }
    b = b2;
    vector<int> ans(n2, -1), used(n, 0);
    int last = 0;
    rep(i, n) {
        // b[i]に対応する要素
        int res = -1;
        rep(j, n) {
            if (b[i] < d[j] && used[j] == 0) {
                res = d[j];
                used[j] = 1;
                break;
            }
        }
        assert(res != -1);
        ans[2 * i] = b[i];
        ans[2 * i + 1] = res;
    }
    rep(i, n2) {
        if (i == 0)
            cout << ans[i];
        else
            cout << " " << ans[i];
    }
    cout << '\n';
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
