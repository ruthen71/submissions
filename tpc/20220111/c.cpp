#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int ans = 0;
int N, M;

vector<string> G;

void dfs(vector<int> &f, vector<int> &used, int x, int y, int carry) {
    if (y == M) {
        if (carry == 0) {
            ans++;
        }
        return;
    }
    if (x == N) {
        int s = carry;
        rep(i, N - 1) {
            if ((int)G[i].size() > y) s += f[G[i][y] - 'A'];
        }
        if (s % 10 != f[G[N - 1][y] - 'A']) return;
        dfs(f, used, 0, y + 1, s / 10);
        return;
    }
    if ((int)G[x].size() <= y) {
        dfs(f, used, x + 1, y, carry);
        return;
    }
    if ((int)G[x].size() - 1 == y) {
        if (f[G[x][y] - 'A'] == 0) return;
        if (f[G[x][y] - 'A'] != -1) {
            dfs(f, used, x + 1, y, carry);
            return;
        }
        for (int i = 1; i < 10; i++) {
            if (used[i]) continue;
            used[i] = 1;
            f[G[x][y] - 'A'] = i;
            dfs(f, used, x + 1, y, carry);
            used[i] = 0;
            f[G[x][y] - 'A'] = -1;
        }
        return;
    }
    if (f[G[x][y] - 'A'] != -1) {
        dfs(f, used, x + 1, y, carry);
        return;
    }
    rep(i, 10) {
        if (used[i]) continue;
        used[i] = 1;
        f[G[x][y] - 'A'] = i;
        dfs(f, used, x + 1, y, carry);
        used[i] = 0;
        f[G[x][y] - 'A'] = -1;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    rep(i, N) {
        string S;
        cin >> S;
        reverse(ALL(S));
        G.push_back(S);
    }
    string T = "";
    rep(i, N) T += G[i];
    sort(ALL(T));
    T.erase(unique(ALL(T)), T.end());
    rep(i, N) {
        for (auto &ci : G[i]) {
            ci = 'A' + lower_bound(ALL(T), ci) - T.begin();
        }
    }
    M = (int)G[N - 1].size();
    int l = T.size();
    vector<int> f(l, -1), used(10, 0);
    dfs(f, used, 0, 0, 0);
    cout << ans << '\n';
    return 0;
}

/**
 * 虫食い算
 * めちゃくちゃ時間かかってしまいました
 * 普通にO(N!)の全列挙をすると間に合わないので、下位桁から決めていく
 * 最上位桁に0が使えないのがややこしい
 * グローバル変数を使いましょう(反省)
 * 今思えば桁数をそろえておくのもアリだったかもしれない
 */
