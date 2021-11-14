#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> c(N);
    rep(i, N) cin >> c[i];
    map<int, int> mp;
    int cnt = 0;
    rep(i, K) {
        if (mp[c[i]] == 0) {
            mp[c[i]]++;
            cnt++;
        } else {
            mp[c[i]]++;
        }
    }
    int ans = cnt;
    rep(i, N - K) {
        mp[c[i]]--;
        if (mp[c[i]] == 0) {
            cnt--;
        }
        if (mp[c[i + K]] == 0) {
            mp[c[i + K]]++;
            cnt++;
        } else {
            mp[c[i + K]]++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
