#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int w;
string s[300005];
int vf[300005];

int H = 4, W = 4;
string g[4];
int seen[4][4];

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int scof[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

void dfs(int i, int j, int p, int ind) {
    if (p + 1 == s[ind].size()) {
        vf[ind] = 1;
        return;
    }
    rep(k, 8) {
        int nx = i + dx[k], ny = j + dy[k];
        if (!(0 <= nx && nx < H && 0 <= ny && ny < W)) continue;
        if (seen[nx][ny]) continue;
        if (s[ind][p + 1] == g[nx][ny]) {
            seen[nx][ny] = 1;
            dfs(nx, ny, p + 1, ind);
            seen[nx][ny] = 0;
        }
    }
}

void solve() {
    rep(i, H) cin >> g[i];
    rep(i, w) vf[i] = 0;
    rep(i, w) {
        string t = s[i];
        vector<int> cnt(26, 0);
        rep(x, 4) rep(y, 4) cnt[g[x][y] - 'A']++;
        rep(j, t.size()) cnt[t[j] - 'A']--;
        int ok = 1;
        rep(j, 26) if (cnt[j] < 0) ok = 0;
        if (ok == 0) continue;
        rep(x, 4) rep(y, 4) seen[x][y] = 0;
        rep(x, 4) rep(y, 4) {
            if (g[x][y] == t[0]) {
                seen[x][y] = 1;
                dfs(x, y, 0, i);
                seen[x][y] = 0;
            }
        }
    }
    int numw = 0, sco = 0;
    string ans = "a";
    rep(i, w) {
        if (vf[i]) {
            numw++;
            sco += scof[s[i].size()];
            if (s[i].size() > ans.size())
                ans = s[i];
            else if (s[i].size() == ans.size() && s[i] < ans)
                ans = s[i];
        }
    }
    cout << sco << " " << ans << " " << numw << '\n';
    return;
}

int main() {
    cin >> w;
    rep(i, w) cin >> s[i];
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
