#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    int S, T, X;
    cin >> S >> T >> X;
    int ok;
    if (S < T) {
        if (S <= X && X < T)
            ok = 1;
        else
            ok = 0;
    } else {
        if (T <= X && X < S)
            ok = 0;
        else
            ok = 1;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}
