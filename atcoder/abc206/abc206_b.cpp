#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N;
    cin >> N;
    ll ans = 0, s = 0;
    while (1) {
        ans++;
        s += ans;
        if (s >= N) {
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}
