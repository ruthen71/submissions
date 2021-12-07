#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    string S, T;
    while (cin >> S, S != "0") {
        cin >> T;
        int ls = S.size(), lt = T.size(), ans1 = 0;
        rep(i, lt - ls + 1) if (T.substr(i, ls) == S) ans1++;
        map<string, int> t2;
        rep(i, ls) {
            string ss = S.substr(0, i) + S.substr(i + 1);
            if (t2[ss] != 0) continue;
            int lss = ls - 1;
            rep(j, lt - lss + 1) {
                if (T.substr(j, lss) == ss) t2[ss]++;
            }
        }
        ll ans2 = 0;
        for (auto p : t2) ans2 += p.second;
        map<string, int> t3;
        string U = "AGCT";
        rep(i, ls + 1) {
            rep(j, 4) {
                string ss = S.substr(0, i) + U[j] + S.substr(i);
                if (t3[ss] != 0) continue;
                int lss = ls + 1;
                rep(j, lt - lss + 1) {
                    if (T.substr(j, lss) == ss) t3[ss]++;
                }
            }
        }
        ll ans3 = 0;
        for (auto p : t3) ans3 += p.second;
        cout << ans1 << " " << ans2 << " " << ans3 << '\n';
    }
    return 0;
}
