#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
const ll INF = 1ll << 60;

int M = 300005;

int main() {
    cout << "?";
    for (int i = 0; i < 100; i++) {
        int a = 127;
        int outp = (a << 7) + i;
        cout << " " << outp;
    }
    cout << endl;
    int res;
    cin >> res;
    cout << "?";
    for (int i = 0; i < 100; i++) {
        int a = 127;
        int outp = (i << 7) + a;
        cout << " " << outp;
    }
    cout << endl;
    int res2;
    cin >> res2;
    int al = (1 << 14) - 1;
    int ans = ((res ^ al) & (127 << 7)) + ((res2 ^ al) & 127);
    cout << "! " << ans << endl;
    return 0;
}
