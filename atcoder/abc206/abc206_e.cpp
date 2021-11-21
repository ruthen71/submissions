#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> Era_list(int n) {
    vector<int> isprime(n + 1, 1);
    vector<int> res;
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) {
            res.push_back(i);
            for (int j = 2 * i; j < n + 1; j += i) isprime[j] = 0;
        }
    }
    return res;
}

int main() {
    int L, R;
    cin >> L >> R;
    if (L == 1) L++;
    vector<int> e = Era_list(1005);
    int es = e.size();
    vector<int> yak(R + 1, 0), cnt(R + 1, 0);
    vector<vector<int>> divs(R + 1);
    for (int x = L; x <= R; x++) {
        int n = x;
        for (int i = 0; i < es && e[i] * e[i] <= n; i++) {
            if (n % e[i] == 0) {
                divs[x].push_back(e[i]);
                while (n % e[i] == 0) n /= e[i];
            }
        }
        if (n != 1) divs[x].push_back(n);
        int sz = divs[x].size();
        for (int b = 1; b < (1 << sz); b++) {
            int mul = 1;
            for (int i = 0; i < sz; i++)
                if (b >> i & 1) mul *= divs[x][i];
            cnt[mul]++;
        }
        for (int y = x; y <= R; y += x) yak[y]++;
    }
    ll ans = 0;
    for (int x = L; x <= R; x++) {
        int sz = divs[x].size();
        for (int b = 1; b < (1 << sz); b++) {
            int mul = 1;
            for (int i = 0; i < sz; i++)
                if (b >> i & 1) mul *= divs[x][i];
            ans += cnt[mul] * ((__builtin_popcount(b) % 2 == 1) ? (1) : -1);
        }
        ans -= yak[x] - 1;
        ans -= R / x - (L - 1) / x;
    }
    cout << ans << endl;
    return 0;
}

/*
包除原理
約数
エラトステネスの篩
互いに素であるペアの数は包除原理を使うとO(N^2)より高速に求めることができる
x/g=1となるものは、xの倍数
y/g=1となるものは、xの約数
なので、どっちもそれぞれ求めて、xだけは重複して数えているので引く
*/