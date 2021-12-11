#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    int N;
    cin >> N;
    map<string, int> mp;
    rep(i, N) {
        string s;
        cin >> s;
        mp[s]++;
    }
    string ans = "";
    for (auto p : mp) {
        if (mp[ans] < p.second) ans = p.first;
    }
    cout << ans << '\n';
    return 0;
}
