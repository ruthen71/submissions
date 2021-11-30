#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if ((s1 == "#." && s2 == ".#") || (s2 == "#." && s1 == ".#"))
        puts("No");
    else
        puts("Yes");

    return 0;
}
