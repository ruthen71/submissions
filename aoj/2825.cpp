#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int inf = 1000000000;

void solve(int n) {
    int m;
    cin >> m;
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < m; i++) {
        int s, k;
        cin >> s >> k;
        vector<int> num(k);
        for (int j = 0; j < k; j++) cin >> num[j];
        if (k == 1) {
            a[num[0] - 1] += s;
            b[num[0] - 1] += s;
        } else {
            for (int j = 0; j < k; j++) b[num[j] - 1] += s;
        }
    }
    vector<int> L(n, inf), R(n, inf);
    for (int i = 1; i < n; i++) {
        L[i] = min(L[i - 1], a[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        R[i] = min(R[i + 1], a[i + 1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, b[i] - min(L[i], R[i]));
    }
    cout << ans + 1 << endl;
    return;
}

int main() {
    int n;
    while (cin >> n, n) solve(n);
    return 0;
}

/*
i=0:n-1について、i番目の人が取れる点を全て取り、残りのn-1人について、
各自が最も点が取れなかったときの点(注:0点とは限らない、自分しか答えられないなら点が入るため)
のうち、一番小さいものを求める
i番目の人が取れる点を全て取った時の値がbに入っている(これは計算できる)
各自が最も点が取れないのはどういう場合かと言うと、複数人が答えられる問題を全部落としたときなので、
k=1のときのみ加算する操作を行う(aに格納)
最後に、n-1人が最も点が取れない時の最小値を求める
これを愚直にやるとO(N)で、全体でO(N^2)だが、左からと右からの累積minを計算しておくことで、O(1)、全体でO(N)でできる
*/
