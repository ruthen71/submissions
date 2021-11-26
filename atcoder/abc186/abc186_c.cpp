#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

ll INF = 1ll << 60;

string to10(int x) {
    string ret = "";
    while (x) {
        ret += '0' + x % 10;
        x /= 10;
    }
    reverse(ALL(ret));
    return ret;
}

string to8(int x) {
    string ret = "";
    while (x) {
        ret += '0' + x % 8;
        x /= 8;
    }
    reverse(ALL(ret));
    return ret;
}

int cont(string s) {
    for (auto ci : s)
        if (ci == '7') return 1;
    return 0;
}

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        string i10 = to10(i);
        string i8 = to8(i);
        if (cont(i10) == 0 and cont(i8) == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}

/*
n進数
n進法
8進数への変換
*/