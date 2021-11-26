#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

ll INF = 1ll << 60;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(m), d(m), c(m);
    rep(i, m) cin >> s[i] >> d[i] >> c[i];
    rep(i, m) s[i]--, d[i]--;
    vector<int> ans(n, -1), test(n, -1);
    rep(i, m) test[d[i]] = i;
    vector<int> pre(m, 0), pro(m, 0);
    int ok = 1;
    for (int day = 0; day < n; day++) {
        rep(i, m) if (day == s[i]) pre[i] = 1;
        if (test[day] != -1) {
            if (pre[test[day]] == 2) {
                ans[day] = m + 1;
                continue;
            }
            assert(pre[test[day]] == 1);
            ok = 0;
            break;
        }
        int todo = -1;
        rep(i, m) {
            if (pre[i] == 1) {
                if (todo == -1) {
                    todo = i;
                } else if (d[i] < d[todo]) {
                    todo = i;
                }
            }
        }
        if (todo == -1) {
            ans[day] = 0;
            continue;
        }
        ans[day] = todo + 1;
        pro[todo]++;
        if (pro[todo] == c[todo]) pre[todo] = 2;
    }
    if (ok) {
        rep(i, n) {
            if (i == 0)
                cout << ans[i];
            else
                cout << " " << ans[i];
        }
        cout << '\n';
    } else {
        cout << -1 << endl;
    }
    return 0;
}
