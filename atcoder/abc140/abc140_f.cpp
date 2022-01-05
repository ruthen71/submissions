#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int N2 = 1 << N;
    vector<int> S(N2);
    rep(i, N2) cin >> S[i];
    multiset<int> rem;
    vector<int> exi;
    sort(ALL(S));
    rep(i, N2 - 1) rem.insert(S[i]);
    rem.insert(-1);
    exi.push_back(S[N2 - 1]);
    for (int i = 0; i < N; i++) {
        int b = 1 << i;
        vector<int> nx;
        for (auto &si : exi) {
            auto it = rem.lower_bound(si);
            it--;
            int m = (*it);
            if (m == -1) return puts("No") & 0;
            nx.push_back(m);
            rem.erase(it);
        }
        assert((int)nx.size() == b);
        for (auto &si : nx) exi.push_back(si);
    }
    puts("Yes");
    return 0;
}

/**
 * 貪欲法
 * LCA
 * 最近共通祖先
 * 1.降順ソートして順番に作れるか->WA
 * 反例:4,3,3,3,2,2,2,1(4->4,3->4,3,3,2->4,3,3,2,3,2,2,1で作れる)
 * 2.小さい奴からやってみる->WA
 * 3.
 * exi={Sの最大値}として
 * 操作を実際にやってみる
 * 追加するときに、「なるべく大きいスライムから作る」として操作すると、通る
 * 証明は公式解説に
 */
