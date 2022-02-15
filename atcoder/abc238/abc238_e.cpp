#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> L(Q), R(Q);
    rep(i, Q) cin >> L[i] >> R[i];
    rep(i, Q) L[i]--;
    vector<vector<int>> Ls(N + 1), Rs(N + 1);
    rep(i, Q) Ls[R[i]].push_back(L[i]);
    rep(i, Q) Rs[L[i]].push_back(R[i]);
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto &nx : Ls[v]) {
            if (dp[nx] == 0) {
                dp[nx] = 1;
                que.push(nx);
            }
        }
        for (auto &nx : Rs[v]) {
            if (dp[nx] == 0) {
                dp[nx] = 1;
                que.push(nx);
            }
        }
    }
    cout << (dp[N] ? "Yes" : "No") << '\n';
    return 0;
}

/**
 * 区間和の情報をcum[r]-cum[l]の値が与えられていると考える
 * cum[0]=0はわかっている
 * 与えられた情報からcum[N]がわかればOK
 * cum[l]がわかればcum[r]がわかるし、cum[r]がわかればcum[l]がわかる
 * よってcum[i]を頂点iに対応させて、0->Nのグラフの連結判定を行えば良い
 */
