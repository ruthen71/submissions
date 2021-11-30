#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

const ll INF = 1ll << 60;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        if (a[l] <= k) {
            l++;
            ans++;
            continue;
        } else if (a[r] <= k) {
            r--;
            ans++;
            continue;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

/**
 * dequeを使うと良かったかもしれない
 * 前から取る操作と後ろから取る操作はそれぞれ1回ずつできるだけやればOK
 */