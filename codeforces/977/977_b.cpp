#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    int n;
    string s;
    cin >> n >> s;
    map<string, int> mp;
    rep(i, n - 1) { mp[s.substr(i, 2)]++; }
    string ans = "AA";
    for (auto p : mp) {
        if (mp[ans] < p.second) ans = p.first;
    }
    cout << ans << endl;
    return 0;
}
