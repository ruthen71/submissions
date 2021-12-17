#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> imos(N + 1, 0);
    rep(i, M) {
        int L, R;
        cin >> L >> R;
        imos[L - 1]++;
        imos[R]--;
    }
    rep(i, N) imos[i + 1] += imos[i];
    int ans = 0;
    rep(i, N) if (imos[i] == M) ans++;
    cout << ans << '\n';
    return 0;
}
