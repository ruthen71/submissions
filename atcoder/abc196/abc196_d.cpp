#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int H, W, A, B, ans;
int used[16][16];

void dfs(int i, int j, int a, int b) {
    if (i == H) {
        ans++;
        return;
    }
    if (j == W) {
        dfs(i + 1, 0, a, b);
        return;
    }
    if (used[i][j] != 0) {
        dfs(i, j + 1, a, b);
        return;
    }
    if (i != H - 1 && a > 0 && used[i + 1][j] == 0) {
        used[i][j] = used[i + 1][j] = 2;
        dfs(i, j + 1, a - 1, b);
        used[i][j] = used[i + 1][j] = 0;
    }
    if (j != W - 1 && a > 0 && used[i][j + 1] == 0) {
        used[i][j] = used[i][j + 1] = 3;
        dfs(i, j + 1, a - 1, b);
        used[i][j] = used[i][j + 1] = 0;
    }
    if (b > 0) {
        used[i][j] = 1;
        dfs(i, j + 1, a, b - 1);
        used[i][j] = 0;
    }
    return;
}

int main() {
    cin >> H >> W >> A >> B;
    dfs(0, 0, A, B);
    cout << ans << '\n';
    return 0;
}

/**
 * DFSする
 * ピースを置く前にそこにピースがまだないかちゃんと確認しよう
 */