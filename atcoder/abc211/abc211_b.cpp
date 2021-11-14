#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    vector<string> s(4);
    rep(i, 4) cin >> s[i];
    sort(s.begin(), s.end());
    if (s[0] == "2B" && s[1] == "3B" && s[2] == "H" && s[3] == "HR") {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}
