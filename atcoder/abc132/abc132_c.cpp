#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int N;
    cin >> N;
    vector<int> d(N);
    rep(i, N) cin >> d[i];
    sort(ALL(d));
    int ans = d[N / 2] - d[N / 2 - 1];
    cout << ans << '\n';
    return 0;
}
