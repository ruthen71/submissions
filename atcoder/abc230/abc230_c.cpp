#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ll N, A, B, P, Q, R, S;
    cin >> N >> A >> B >> P >> Q >> R >> S;
    ll H = Q - P + 1, W = S - R + 1;
    vector<vector<int>> G(H, vector<int>(W, 0));
    rep(i, H) rep(j, W) {
        ll cx = P + i, cy = R + j;
        ll k = cx - A;
        if (B + k == cy) {
            if (max(1 - A, 1 - B) <= k && k <= min(N - A, N - B)) G[i][j] = 1;
        }
        if (B - k == cy) {
            if (max(1 - A, B - N) <= k && k <= min(N - A, B - 1)) G[i][j] = 1;
        }
    }
    rep(i, H) {
        rep(j, W) {
            if (G[i][j])
                cout << "#";
            else
                cout << ".";
        }
        cout << '\n';
    }
    return 0;
}
