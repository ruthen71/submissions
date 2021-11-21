#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

const ll INF = 3000000000000000000ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        vector<ll> ans;
        vector<int> used(n, 0);
        ll cur = a[i];
        ans.push_back(a[i]);
        used[i] = 1;
        while (1) {
            int ok = 0;
            rep(j, n) {
                if (used[j]) continue;
                if (cur % 3 == 0 && cur / 3 == a[j]) {
                    cur = a[j];
                    ans.push_back(a[j]);
                    used[j] = 1;
                    ok = 1;
                    break;
                } else if (cur <= INF / 2 && cur * 2 == a[j]) {
                    cur = a[j];
                    ans.push_back(a[j]);
                    used[j] = 1;
                    ok = 1;
                    break;
                }
            }
            if (ok == 0) break;
        }
        if (ans.size() != n) {
            continue;
        } else {
            cout << ans[0];
            rep(i, n - 1) cout << " " << ans[i + 1];
            cout << '\n';
            return 0;
        }
    }
    return 0;
}
