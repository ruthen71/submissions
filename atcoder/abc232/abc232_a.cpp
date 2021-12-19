#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    string s;
    cin >> s;
    int a = s[0] - '0', b = s[2] - '0';
    cout << a * b << '\n';
    return 0;
}
