#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    rep(i, N) A[i]--;
    X--;
    vector<int> seen(N, 0);
    while (1) {
        if (seen[X]) break;
        seen[X] = 1;
        X = A[X];
    }
    int ans = 0;
    rep(i, N) ans += seen[i];
    cout << ans << endl;
    return 0;
}
