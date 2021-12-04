#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ok2 = 0;
    rep(k, 3) {
        int ok = 1;
        rep(i, n) {
            if (s[i] == 'o' && (i + k) % 3 == 0)
                continue;
            else if (s[i] == 'x' && (i + k) % 3 != 0)
                continue;
            ok = 0;
        }
        ok2 = max(ok2, ok);
    }
    puts(ok2 ? "Yes" : "No");
    return 0;
}
