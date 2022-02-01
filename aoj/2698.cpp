#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int H, W;
int grundy[22][22][22][22];
string g[22];

int rec(int h1, int h2, int w1, int w2) {
    if (grundy[h1][h2][w1][w2] != -1) return grundy[h1][h2][w1][w2];
    if (h1 == h2 || w1 == w2) return 0;
    set<int> s;
    for (int i = h1; i < h2; i++) {
        for (int j = w1; j < w2; j++) {
            if (g[i][j] == 'X') continue;
            int c = 0;
            c ^= rec(h1, i, w1, j);
            c ^= rec(h1, i, j + 1, w2);
            c ^= rec(i + 1, h2, w1, j);
            c ^= rec(i + 1, h2, j + 1, w2);
            s.insert(c);
        }
    }
    int g = 0;
    while (s.count(g) != 0) g++;
    return grundy[h1][h2][w1][w2] = g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> H >> W;
    rep(i, H) cin >> g[i];
    rep(h1, 22) rep(h2, 22) rep(w1, 22) rep(w2, 22) grundy[h1][h2][w1][w2] = -1;
    int a = rec(0, H, 0, W);
    cout << (a ? "First" : "Second") << "\n";
    return 0;
}

/**
 * 解説AC
 * チーム練で登場し、チームメイトに聞いた
 * Grundy数
 * 操作をすると盤面が4つに分かれると考えれば良い
 */
