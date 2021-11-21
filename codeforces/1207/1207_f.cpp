#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

ll a[500005], b[705][705];

int main() {
    int Q;
    cin >> Q;
    vector<int> vx(Q), vy(Q), vt(Q);
    rep(i, Q) cin >> vt[i] >> vx[i] >> vy[i];
    rep(i, Q) {
        int t = vt[i], x = vx[i], y = vy[i];
        if (t == 1) {
            a[x] += y;
            for (int i = 1; i <= 700; i++) b[i][x % i] += y;
        } else {
            if (x <= 700) {
                cout << b[x][y] << '\n';
            } else {
                ll s = 0;
                for (int i = y; i <= 500000; i += x) s += a[i];
                cout << s << '\n';
            }
        }
    }
    return 0;
}

/*
解説AC
平方分割し、xが大きい時には愚直に求める
xが小さい時にはあらかじめ剰余を求めておく
*/
