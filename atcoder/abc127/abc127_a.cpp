#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int A, B;
    cin >> A >> B;
    if (A <= 12) B /= 2;
    if (A <= 5) B = 0;
    cout << B << '\n';
    return 0;
}
