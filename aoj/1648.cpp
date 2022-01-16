#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(4);
    while (true) {
        rep(i, 4) cin >> a[i];
        vector<int> ind;
        rep(i, 4) if (a[i] != 0) ind.push_back(i);
        if (ind.size() == 0) break;
        while (true) {
            if (ind.size() == 1) {
                cout << a[ind[0]] << '\n';
                break;
            }
            int idx = ind[0];
            for (auto i : ind)
                if (a[i] < a[idx]) idx = i;
            for (auto i : ind)
                if (i != idx) a[i] -= a[idx];
            vector<int> nx;
            rep(i, 4) if (a[i] != 0) nx.push_back(i);
            ind = nx;
        }
    }
    return 0;
}

/**
 * 当時はチームメイトが解いた
 * 普通にシミュレーションする
 */
