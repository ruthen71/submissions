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
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int c = 1;
    rep(i, N) {
        if (c == A[i]) c++;
    }
    cout << (c == 1 ? -1 : N - c + 1) << '\n';
    return 0;
}
