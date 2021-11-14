#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    rep(i, s.size()) {
        if (s[i] == '1') {
            cout << (i % 2 == 0 ? "Takahashi" : "Aoki") << endl;
            return 0;
        }
    }
    return 0;
}
