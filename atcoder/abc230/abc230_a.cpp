#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    int N;
    cin >> N;
    if (N >= 42) N++;
    cout << "AGC0" << ((N < 10) ? "0" : "") << N << '\n';
    return 0;
}
