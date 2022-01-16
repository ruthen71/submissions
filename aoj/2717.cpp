#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<string> S(M);
    rep(i, M) cin >> S[i];
    vector<int> A(N + 1, 0);
    rep(i, M) {
        // 左側のEの数
        int cnt = 0;
        rep(j, N) {
            if (S[i][j] == 'E') cnt++;
            A[j + 1] += cnt;
        }
        // 右側のWの数
        cnt = 0;
        for (int j = N - 1; j >= 0; j--) {
            if (S[i][j] == 'W') cnt++;
            A[j] += cnt;
        }
    }
    int ans = 0;
    rep(j, N + 1) {
        if (A[j] < A[ans]) ans = j;
    }
    cout << ans << " " << ans + 1 << '\n';
    return 0;
}

/**
 * ある部分で区切った時の左側のEの数と右側のWの数を前計算する
 */
