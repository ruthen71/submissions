#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> ac(N, 0), wa(N, 0);
    int acc = 0, wac = 0;
    rep(i, M) {
        int id;
        string s;
        cin >> id >> s;
        id--;
        if (s == "AC") {
            if (ac[id] == 0) {
                ac[id] = 1;
                acc++;
                wac += wa[id];
            }
        } else {
            wa[id]++;
        }
    }
    cout << acc << " " << wac << '\n';
    return 0;
}
