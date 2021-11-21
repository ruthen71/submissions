#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

ll N = 1 << 20;

int main() {
    ll Q;
    cin >> Q;
    set<ll> S;
    rep(i, N) S.insert(i);
    vector<ll> t(Q), x(Q);
    rep(i, Q) cin >> t[i] >> x[i];
    vector<ll> A(N, -1);
    rep(i, Q) {
        if (t[i] == 1) {
            auto itr = S.lower_bound(x[i] % N);
            if (itr == S.end()) {
                itr = S.lower_bound(0);
            }
            A[(*itr)] = x[i];
            S.erase(itr);
        } else {
            cout << A[x[i] % N] << '\n';
        }
    }
    return 0;
}

/*
UnionFindの経路圧縮っぽいことをすれば良いけど、setのほうが楽
*/