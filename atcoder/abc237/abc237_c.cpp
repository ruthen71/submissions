#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    int l = 10000000, r = -1, n = S.size();
    rep(i, n) {
        if (S[i] != 'a') {
            l = min(l, i);
            r = max(r, i);
        }
    }
    if (r == -1) {
        cout << "Yes" << '\n';
        return 0;
    }
    if (l > n - 1 - r) {
        cout << "No" << '\n';
        return 0;
    }
    int ok = 1;
    for (int i = l; i <= r; i++) {
        if (S[i] != S[r - (i - l)]) {
            ok = 0;
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}

/**
 * aのみからなる時と、そうでない時で場合分けする
 */
