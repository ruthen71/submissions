#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll K;
    cin >> K;
    vector<int> ans;
    while (K) {
        ans.push_back(2 * (K & 1));
        K >>= 1;
    }
    reverse(ALL(ans));
    for (auto &a : ans) cout << a;
    cout << '\n';
    return 0;
}

/**
 * 2進法の1を2にする
 */
