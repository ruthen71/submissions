#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

ll INF = 1ll << 40;

int main() {
    ll N;
    cin >> N;
    ll lb = -INF, ub = INF;
    ll d = 0, ma = INF, mi = -INF;
    rep(i, N) {
        ll a, t;
        cin >> a >> t;
        if (t == 1) {
            d += a;
        }
        if (t == 2) {
            lb = max(lb, a - d);
            mi = max(mi + d, a) - d;
            ma = max(ma + d, a) - d;
        }
        if (t == 3) {
            ub = min(ub, a - d);
            ma = min(ma + d, a) - d;
            mi = min(mi + d, a) - d;
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        ll x;
        cin >> x;
        if (lb <= x && x <= ub) {
            cout << x + d << '\n';
        } else if (lb <= x) {
            cout << ma + d << '\n';
        } else {
            cout << mi + d << '\n';
        }
    }
    return 0;
}

/**
 * clamp関数
 * クエリ問題
 * 関数合成
 * 暫く定数で右上がりの直線、またそこから定数、みたいなものを見たらclamp関数の合成を考える
 * minとmaxの入り組んだ式に関する公式
 * max(a,min(b,c))=min(max(a,b),max(a,c))
 * min(a,max(b,c))=max(min(a,b),min(a,c))
 */