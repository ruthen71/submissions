#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    string s, t;
    cin >> s >> t;
    int diff = (t[0] - s[0] + 26) % 26;
    int ok = 1;
    int n = s.size();
    rep(i, n) {
        int a = s[i] - 'a', b = t[i] - 'a';
        if ((a + diff) % 26 != b) ok = 0;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}
