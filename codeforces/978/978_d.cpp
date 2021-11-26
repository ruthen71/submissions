#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

ll INF = 1ll << 60;

int main() {
    int n;
    cin >> n;
    vector<ll> b(n);
    rep(i, n) cin >> b[i];
    if (n <= 2) return puts("0") & 1;
    ll d = b[1] - b[0];
    ll ans = INF;
    for (int di = d - 2; di <= d + 2; di++) {
        ll c = 0;
        vector<ll> a = b;
        rep(i, n - 1) {
            if (a[i] + di == a[i + 1])
                continue;
            else if (a[i] + di == a[i + 1] - 1) {
                a[i + 1]--;
                c++;
            } else if (a[i] + di == a[i + 1] + 1) {
                a[i + 1]++;
                c++;
            } else {
                c = INF;
            }
        }
        ans = min(ans, c);
        c = 1;
        a = b;
        a[0]--;
        rep(i, n - 1) {
            if (a[i] + di == a[i + 1])
                continue;
            else if (a[i] + di == a[i + 1] - 1) {
                a[i + 1]--;
                c++;
            } else if (a[i] + di == a[i + 1] + 1) {
                a[i + 1]++;
                c++;
            } else {
                c = INF;
            }
        }
        ans = min(ans, c);
        c = 1;
        a = b;
        a[0]++;
        rep(i, n - 1) {
            if (a[i] + di == a[i + 1])
                continue;
            else if (a[i] + di == a[i + 1] - 1) {
                a[i + 1]--;
                c++;
            } else if (a[i] + di == a[i + 1] + 1) {
                a[i + 1]++;
                c++;
            } else {
                c = INF;
            }
        }
        ans = min(ans, c);
    }
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}
