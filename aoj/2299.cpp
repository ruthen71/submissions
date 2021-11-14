#include <bits/stdc++.h>
using namespace std;

int T = 26;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    for (int i = 0; i < H; i++) cin >> C[i];
    vector<int> exi(T, 0);
    vector<vector<int>> vx(T), vy(T);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (C[i][j] != '.') {
                exi[C[i][j] - 'A'] = 1;
                vx[C[i][j] - 'A'].push_back(i);
                vy[C[i][j] - 'A'].push_back(j);
            }
        }
    }
    int ans = 0;
    for (int t = 0; t < T + 5; t++) {
        for (int c = 0; c < T; c++) {
            if (exi[c] == 0) continue;
            C[vx[c][0]][vy[c][0]] = '.';
            C[vx[c][1]][vy[c][1]] = '.';
            int ok = 1;
            if (vx[c][0] == vx[c][1]) {
                if (abs(vy[c][0] - vy[c][1]) <= 1) ok = 0;
                for (int j = vy[c][0]; j <= vy[c][1]; j++) {
                    if (C[vx[c][0]][j] != '.') ok = 0;
                }
            } else if (vy[c][0] == vy[c][1]) {
                if (abs(vx[c][0] - vx[c][1]) <= 1) ok = 0;
                for (int i = vx[c][0]; i <= vx[c][1]; i++) {
                    if (C[i][vy[c][0]] != '.') ok = 0;
                }
            } else {
                if (vy[c][0] < vy[c][1]) {
                    int ok1 = 1;
                    for (int j = vy[c][0]; j <= vy[c][1]; j++)
                        if (C[vx[c][0]][j] != '.') ok1 = 0;
                    for (int i = vx[c][0]; i <= vx[c][1]; i++)
                        if (C[i][vy[c][1]] != '.') ok1 = 0;
                    int ok2 = 1;
                    for (int j = vy[c][0]; j <= vy[c][1]; j++)
                        if (C[vx[c][1]][j] != '.') ok2 = 0;
                    for (int i = vx[c][0]; i <= vx[c][1]; i++)
                        if (C[i][vy[c][0]] != '.') ok2 = 0;
                    ok = max(ok1, ok2);
                } else {
                    int ok1 = 1;
                    for (int j = vy[c][1]; j <= vy[c][0]; j++)
                        if (C[vx[c][0]][j] != '.') ok1 = 0;
                    for (int i = vx[c][0]; i <= vx[c][1]; i++)
                        if (C[i][vy[c][1]] != '.') ok1 = 0;
                    int ok2 = 1;
                    for (int j = vy[c][1]; j <= vy[c][0]; j++)
                        if (C[vx[c][1]][j] != '.') ok2 = 0;
                    for (int i = vx[c][0]; i <= vx[c][1]; i++)
                        if (C[i][vy[c][0]] != '.') ok2 = 0;
                    ok = max(ok1, ok2);
                }
            }
            if (ok) {
                ans += 2;
                exi[c] = 0;
            } else {
                C[vx[c][0]][vy[c][0]] = c + 'A';
                C[vx[c][1]][vy[c][1]] = c + 'A';
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
26回消せるか確認して消すだけ
350なのこれ？
*/