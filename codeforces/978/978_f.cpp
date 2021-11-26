#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

ll INF = 1ll << 60;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    rep(i, n) cin >> r[i];
    vector<int> r2 = r;
    sort(ALL(r2));
    r2.erase(unique(ALL(r2)), r2.end());
    rep(i, n) r[i] = lower_bound(ALL(r2), r[i]) - r2.begin();
    vector<vector<int>> g(n);
    rep(i, n) g[r[i]].push_back(i);
    vector<int> mi(n, 0);
    rep(i, k) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (r[x] == r[y])
            continue;
        else if (r[x] > r[y])
            mi[x]--;
        else
            mi[y]--;
    }
    vector<int> ans(n);
    int s = 0;
    rep(i, n) {
        for (auto p : g[i]) {
            ans[p] = s + mi[p];
        }
        s += g[i].size();
    }
    rep(i, n) {
        if (i == 0)
            cout << ans[i];
        else
            cout << " " << ans[i];
    }
    cout << '\n';
    return 0;
}
