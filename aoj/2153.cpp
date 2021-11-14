#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int dp[52][52][52][52];

int dx1[4] = {1, 0, -1, 0};
int dy1[4] = {0, 1, 0, -1};
int dx2[4] = {1, 0, -1, 0};
int dy2[4] = {0, -1, 0, 1};

struct po {
    int r1x, r1y, r2x, r2y;
};

int main() {
    int H, W;
    while (cin >> W >> H, H) {
        vector<string> r1(H), r2(H);
        rep(i, H) cin >> r1[i] >> r2[i];
        rep(i, H) rep(j, W) rep(k, H) rep(l, W) dp[i][j][k][l] = 0;

        po s, g;
        rep(i, H) rep(j, W) {
            if (r1[i][j] == 'L') s.r1x = i, s.r1y = j;
            if (r1[i][j] == '%') g.r1x = i, g.r1y = j;
            if (r2[i][j] == 'R') s.r2x = i, s.r2y = j;
            if (r2[i][j] == '%') g.r2x = i, g.r2y = j;
        }
        queue<po> que;
        que.push(s);
        dp[s.r1x][s.r1y][s.r2x][s.r2y] = 1;
        while (!que.empty()) {
            po c = que.front();
            que.pop();
            rep(k, 4) {
                po nex;
                nex.r1x = c.r1x + dx1[k];
                nex.r1y = c.r1y + dy1[k];
                nex.r2x = c.r2x + dx2[k];
                nex.r2y = c.r2y + dy2[k];
                if ((!(0 <= nex.r1x && nex.r1x < H && 0 <= nex.r1y && nex.r1y < W)) || (r1[nex.r1x][nex.r1y] == '#')) nex.r1x = c.r1x, nex.r1y = c.r1y;
                if ((!(0 <= nex.r2x && nex.r2x < H && 0 <= nex.r2y && nex.r2y < W)) || (r2[nex.r2x][nex.r2y] == '#')) nex.r2x = c.r2x, nex.r2y = c.r2y;
                if (dp[nex.r1x][nex.r1y][nex.r2x][nex.r2y] == 0) {
                    if (r1[nex.r1x][nex.r1y] == '%') {
                        if (r2[nex.r2x][nex.r2y] == '%') {
                            dp[nex.r1x][nex.r1y][nex.r2x][nex.r2y] = 1;
                            que.push(nex);
                        }
                    } else if (r2[nex.r2x][nex.r2y] != '%') {
                        dp[nex.r1x][nex.r1y][nex.r2x][nex.r2y] = 1;
                        que.push(nex);
                    }
                }
            }
        }
        if (dp[g.r1x][g.r1y][g.r2x][g.r2y])
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

/*
現在地のペアを持ってBFSする
片方が先についてしまう場合は除外する
*/
