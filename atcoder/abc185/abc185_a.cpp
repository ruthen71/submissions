#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int ans = 1000000;
    rep(i, 4) {
        int a;
        cin >> a;
        ans = min(ans, a);
    }
    cout << ans << endl;
    return 0;
}
