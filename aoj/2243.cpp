#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const int INF = 1 << 30;

const int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
const int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

void solve(string &S) {
    int N = (int)S.size();
    vector<int> a(N);
    rep(i, N) a[i] = S[i] - '1';
    // 最初の足の配置と、どっちの足から動くかを全探索する
    int ans = INF;
    rep(l, 9) rep(r, 9) rep(k, 2) {
        int lx = dx[l], ly = dy[l], rx = dx[r], ry = dy[r];
        if (lx > rx) continue;
        int nex = k;
        int cur = 0;
        rep(i, N) {
            if (nex) {
                // 左足を動かす
                int nx = dx[a[i]], ny = dy[a[i]];
                if (nx > rx) {
                    // 右足を動かすことにする
                    cur++;
                    rx = nx, ry = ny;
                } else {
                    lx = nx, ly = ny;
                    nex ^= 1;
                }
            } else {
                // 右足を動かす
                int nx = dx[a[i]], ny = dy[a[i]];
                if (lx > nx) {
                    // 左足を動かすことにする
                    lx = nx, ly = ny;
                    cur++;
                } else {
                    rx = nx, ry = ny;
                    nex ^= 1;
                }
            }
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    while (cin >> S, S != "#") solve(S);
    return 0;
}

/**
 * 最初の足の配置と、どっちの足から動くかを全探索する
 * どっちの足で踏んでも良いときに、わざわざ本来使うべき足じゃない方を使う必要がない
 * ことが示せるので貪欲法が使える
 * どっちの足で踏んでも良い->今右足も左足も同じ列にあり、次に踏む足も同じ列にあるとき
 * 処理後もまた同じ列にある、その次の足がnatural footstep styleではないとき
 * 前もって違反しておく->違反しない
 * 違反しないでおく->違反する
 * となって結局同じ回数だけ違反しているから
 */
