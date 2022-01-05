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
    vector<pair<int, int>> A(N);
    rep(i, N) cin >> A[i].first;
    rep(i, N) A[i].second = i + 1;
    sort(ALL(A));
    rep(i, N) cout << A[i].second << (i == N - 1 ? '\n' : ' ');
    return 0;
}
