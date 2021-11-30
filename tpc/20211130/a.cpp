#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    int k;
    cin >> k;
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int a = 0;
    rep(i, n) if (s1[i] == s2[i]) a++;
    int b = n - a;
    if (a >= k) {
        cout << k + b << '\n';
    } else {
        int t = k - a;
        cout << a + b - t << '\n';
    }
    return 0;
}

/**
 * 共通数をaとするとa>=kのときk+(n-a)でa<kのときa+(n-a)-(k-a)
 * LR貪欲系というらしい？
 */
