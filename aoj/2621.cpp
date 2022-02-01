#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

map<pair<int, int>, int> mp;

const int dx1[4] = {0, 0, -1, -1};
const int dy1[4] = {0, -1, 0, -1};

const int dx[4] = {0, 1, 0, 1};
const int dy[4] = {0, 0, 1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> x(N), y(N), w(N);
    rep(i, N) cin >> x[i] >> y[i] >> w[i];
    rep(i, N) mp[{x[i], y[i]}] = i + 1;
    int ans = 0;
    rep(i, N) {
        // 大きさ1の正方形を考える
        rep(s, 4) {
            int cx = x[i] + dx1[s], cy = y[i] + dy1[s];
            int ws = 0;
            rep(k, 4) {
                int nx = cx + dx[k], ny = cy + dy[k];
                int id = mp[{nx, ny}];
                if (id != 0) {
                    ws += w[id - 1];
                }
            }
            ans = max(ans, ws);
        }
    }
    cout << ans << " / 1\n";
    return 0;
}

/**
 * 実は答えとなるのは大きさ1の正方形だけ
 * これは2つの領域をマージすることを考えると証明できる
 */
