#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0, cnt = 0;
    rep(i, n) {
        if (s[i] == 'x')
            cnt++;
        else {
            ans += max(0, cnt - 2);
            cnt = 0;
        }
    }
    ans += max(0, cnt - 2);
    cout << ans << endl;
    return 0;
}
