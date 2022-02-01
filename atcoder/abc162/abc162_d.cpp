#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

char f(char a, char b) {
    if (a > b) swap(a, b);
    if (a == 'B' && b == 'G') return 'R';
    if (a == 'B' && b == 'R') return 'G';
    if (a == 'G' && b == 'R') return 'B';
    assert(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    string S;
    cin >> N >> S;
    ll ans = 0;
    map<char, ll> mp;
    mp[S[0]]++;
    for (int j = 1; j < N; j++) {
        for (int k = j + 1; k < N; k++) {
            if (S[j] == S[k]) continue;
            char c = f(S[j], S[k]);
            ans += mp[c];
            int d = k - j;
            if (j - d >= 0 && S[j - d] == c) ans--;
        }
        mp[S[j]]++;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * j,kを決めると、[0,j)におけるSj,Skと違う文字の個数が分かれば良い
 * ただj-i=k-jが成り立つところにあるときには適宜-1する
 */
