#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    map<int, ll> mp;
    ll ans = 0;
    rep(i, N) {
        ans += (i - mp[A[i]]);
        mp[A[i]]++;
    }
    cout << ans << endl;
    return 0;
}
