#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void solve(int N, int L) {
    vector<int> TL(L + 1, -1), TR(L + 1, -1);
    rep(i, N) {
        char c;
        int p;
        cin >> c >> p;
        if (c == 'R') {
            TR[p] = i;
        } else {
            TL[p] = i;
        }
    }
    int fnl = -1, cnt = 0, ans;
    rep(t, 1000) {
        if (cnt == N) {
            ans = t;
            break;
        }
        vector<int> nTL(L + 1, -1), nTR(L + 1, -1);
        for (int i = 1; i < L; i++) {
            if (TL[i] == -1) continue;
            if (i - 2 > 0 && TR[i - 2] != -1) {
                nTR[i - 1] = TL[i];
            } else {
                nTL[i - 1] = TL[i];
            }
        }
        for (int i = 1; i < L; i++) {
            if (TR[i] == -1) continue;
            if (i + 2 < L && TL[i + 2] != -1) {
                nTL[i + 1] = TR[i];
            } else {
                nTR[i + 1] = TR[i];
            }
        }
        if (nTR[L] != -1) {
            fnl = nTR[L];
            cnt++;
        }
        if (nTL[0] != -1) {
            fnl = nTL[0];
            cnt++;
        }
        TL = nTL;
        TR = nTR;
    }
    cout << ans << " " << fnl + 1 << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, L;
    while (cin >> N >> L, N != 0 && L != 0) solve(N, L);
    return 0;
}

/**
 * Antsの強化版と思いきや普通に1ターンずつシミュレーションすればOK
 */
