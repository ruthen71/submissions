#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    int n, k;
    cin >> n >> k;
    rep(i, k) {
        if (n % 10 != 0)
            n--;
        else
            n /= 10;
    }
    cout << n << '\n';
    return 0;
}

/*
R479
Codeforces Round 479
Div3
*/
