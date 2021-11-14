#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

void solve(int M) {
    int T, P, R;
    cin >> T >> P >> R;
    vector<vector<int>> da(T, vector<int>(P, -1)), pena(T, vector<int>(P, 0));
    vector<int> accnt(T, 0);
    rep(i, R) {
        int m, t, p, j;
        cin >> m >> t >> p >> j;
        t--, p--;
        if (j == 0) {
            da[t][p] = m;
            accnt[t]++;
        } else {
            pena[t][p]++;
        }
    }
    // {accnt, time}, team number
    vector<pair<pair<int, int>, int>> tem(T);
    rep(i, T) {
        int psum = 0;
        rep(j, P) {
            if (da[i][j] != -1) {
                psum += da[i][j];
                psum += pena[i][j] * 20;
            }
        }
        tem[i] = {{-accnt[i], psum}, -i};
    }
    sort(all(tem));
    rep(i, sz(tem)) {
        if (i != 0) {
            if (tem[i - 1].first.first == tem[i].first.first && tem[i - 1].first.second == tem[i].first.second) {
                cout << "=";
            } else {
                cout << ",";
            }
        }
        cout << -tem[i].second + 1;
    }
    cout << endl;
    return;
}

int main() {
    int M;
    while (cin >> M, M) solve(M);
    return 0;
}

/*
AC数とその時間とそれまでのペナなどをメモしながらやっていく
ソートは-を付けて工夫する
*/