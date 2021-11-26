#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> seen(1005, 0), ans;
    for (int i = N - 1; i >= 0; i--) {
        if (seen[A[i]] == 0) {
            ans.push_back(A[i]);
            seen[A[i]] = 1;
        }
    }
    reverse(ALL(ans));
    cout << SZ(ans) << '\n';
    rep(i, SZ(ans)) {
        if (i == 0)
            cout << ans[i];
        else
            cout << " " << ans[i];
    }
    cout << '\n';
    return 0;
}

/**
 * 右から出てきてないやつを追加
 */
