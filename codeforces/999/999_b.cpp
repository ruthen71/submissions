#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i != n / i) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    vector<ll> d = divisor(n);
    for (auto &di : d) {
        string ts = t.substr(0, di), ts2 = t.substr(di, n - di);
        reverse(ALL(ts));
        t = ts + ts2;
    }
    cout << t << '\n';
    return 0;
}

/**
 * ここでわざわざ約数列挙するの下手
 * reverse(t.begin(), t.begin()+di)でOKだし、diはdi=1...nをやればOK
 */