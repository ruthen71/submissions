#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L, R;
    cin >> L >> R;
    string S;
    cin >> S;
    string t = S.substr(L - 1, R - L + 1);
    reverse(ALL(t));
    string ans = S.substr(0, L - 1) + t + S.substr(R);
    cout << ans << '\n';
    return 0;
}
