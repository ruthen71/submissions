#include <bits/stdc++.h>
using namespace std;

#include <atcoder/dsu>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int M = 200005;

int main() {
    int N;
    cin >> N;
    dsu uf(M);
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int ans = 0;
    rep(i, N / 2) {
        if (!uf.same(A[i], A[N - 1 - i])) {
            ans++;
            uf.merge(A[i], A[N - 1 - i]);
        }
    }
    cout << ans << endl;
    return 0;
}
