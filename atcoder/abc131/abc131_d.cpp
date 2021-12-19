#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int N;
    cin >> N;
    vector<pair<ll, ll>> ab(N);
    rep(i, N) cin >> ab[i].second >> ab[i].first;
    sort(ALL(ab));
    int ok = 1;
    ll ts = 0;
    rep(i, N) {
        ts += ab[i].second;
        if (ts > ab[i].first) ok = 0;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}
