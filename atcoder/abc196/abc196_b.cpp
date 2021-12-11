#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    string s;
    cin >> s;
    int n = s.size();
    rep(i, n) {
        if (s[i] == '.') break;
        cout << s[i];
    }
    cout << '\n';
    return 0;
}

/**
 * std::findを使うと楽
 * cout << s.substr(0, find(s.begin(), s.end(), '.') - s.begin()) << endl;
 */