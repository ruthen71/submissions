#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    string S;
    while (getline(cin, S)) {
        int n = S.size();
        string T = "problem", U = "PROBLEM";
        int ok = 0;
        rep(i, n - 6) {
            int ok2 = 1;
            rep(j, 7) {
                if (S[i + j] != T[j] && S[i + j] != U[j]) ok2 = 0;
            }
            ok = max(ok, ok2);
        }
        puts(ok ? "yes" : "no");
    }
    return 0;
}
