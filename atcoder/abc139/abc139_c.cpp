#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N) cin >> H[i];
    int ans = 0, cur = 0;
    rep(i, N - 1) {
        if (H[i] < H[i + 1]) {
            cur = 0;
        } else {
            cur++;
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
    return 0;
}
