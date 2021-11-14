#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N, A, X, Y;
    cin >> N >> A >> X >> Y;
    cout << max(0ll, N - A) * Y + min(N, A) * X << endl;
    return 0;
}
