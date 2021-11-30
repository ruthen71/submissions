#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    string S;
    ll K;
    cin >> S >> K;
    ll N = SZ(S), c = 0, r = 0, ans = 0;
    rep(l, N) {
        while (r < N && c <= K) {
            if (S[r] == '.') {
                if (c == K) break;
                c++;
            }
            r++;
        }
        ans = max(ans, r - l);
        if (S[l] == '.') c--;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * 尺取り法
 * .の数がK個になっても、Xである限りは右に伸ばせることに注意
 */
