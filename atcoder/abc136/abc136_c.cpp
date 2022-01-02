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
    int ok = 1, m = 0;
    rep(i, N) {
        if (m <= H[i] - 1)
            m = H[i] - 1;
        else if (m <= H[i])
            m = H[i];
        else
            ok = 0;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}

/**
 * 貪欲法
 * 左から見るならなるべく低くしておくと良い
 * ABC-C
 */
