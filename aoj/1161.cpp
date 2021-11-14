#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll INF = 1ll << 60;

int ans, N, M;
int abcd[10];

void rec(vector<vector<int>> &t, vector<int> &u, vector<int> &cnt, int x, int y, int up) {
    if (x == 0 && y == t[N - 1].size()) {
        if (up == 0) ans++;
        return;
    }
    if (x == N) {
        int s = up;
        for (int i = 0; i < N - 1; i++) {
            if (t[i][y] != -1) s += u[t[i][y]];
        }
        if (s % 10 != u[t[N - 1][y]]) return;
        for (int i = 0; i < N; i++) {
            if (t[i][y] != -1 && u[t[i][y]] == 0 && y != 0 && (y + 1 >= t[N - 1].size() || t[i][y + 1] == -1)) return;
        }
        rec(t, u, cnt, 0, y + 1, s / 10);
        return;
    }

    if (t[x][y] == -1) {
        // 次
        rec(t, u, cnt, x + 1, y, up);
        return;
    }
    if (u[t[x][y]] == -1) {
        for (int i = abcd[t[x][y]]; i < 10; i++) {
            if (cnt[i] == 0) {
                if (i == 0 && y != 0 && (y + 1 >= t[N - 1].size() || t[x][y + 1] == -1)) continue;
                u[t[x][y]] = i;
                cnt[i] = 1;
                // 次
                rec(t, u, cnt, x + 1, y, up);
                u[t[x][y]] = -1;
                cnt[i] = 0;
            }
        }
        return;
    }
    rec(t, u, cnt, x + 1, y, up);
    return;
}

void solve(int n) {
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n - 1; i++) {
        if (s[i].size() > s[n - 1].size()) {
            cout << 0 << endl;
            return;
        }
    }
    vector<char> z;
    for (int i = 0; i < n; i++) {
        for (char c : s[i]) {
            z.push_back(c);
        }
    }
    for (int i = 0; i < 10; i++) abcd[i] = 0;
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(), z.end()), z.end());
    vector<vector<int>> t(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].size(); j++) {
            t[i].push_back(lower_bound(z.begin(), z.end(), s[i][j]) - z.begin());
        }
        if (t[i].size() >= 2) abcd[t[i][0]] = 1;
        reverse(t[i].begin(), t[i].end());
        for (int j = 0; j < (int)s[n - 1].size() - (int)s[i].size(); j++) t[i].push_back(-1);
    }
    int m = z.size();
    M = m;
    N = n;
    vector<int> u(m, -1), cnt(10, 0);
    ans = 0;
    rec(t, u, cnt, 0, 0, 0);
    cout << ans << endl;

    return;
}

int main() {
    int n;
    while (cin >> n, n) solve(n);
    return 0;
}

/*
覆面算
next_permutationをするとTLEする
下の桁から決めていくDFSで枝刈を行うことで通る
最上位の桁が0になってはいけない(ただし0はOK)という制限でかなりバグを埋め込んでしまった
一応そこそこ速い
*/
