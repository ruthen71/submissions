#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const ll INF = 1ll << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> P(N);
    rep(i, N) cin >> P[i];
    // P[i]+P[j]=j-i(i<j)
    // i+P[i]=j-P[j]
    set<pair<ll, int>> Set1;  // {i+P[i],i}
    set<pair<ll, int>> Set2;  // {j-P[j],j}
    rep(i, N) {
        Set1.insert({i + P[i], i});
        Set2.insert({i - P[i], i});
    }
    Set1.insert({-INF, -1});  // 番兵
    Set2.insert({INF, -1});   // 番兵
    queue<int> que;
    vector<int> seen(N, 0);
    que.push(0);
    seen[0] = 1;
    Set1.erase({0 + P[0], 0});
    Set2.erase({0 - P[0], 0});
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        auto it1 = Set1.lower_bound({v - P[v], v});
        it1--;
        vector<int> nxv;
        while (it1->first == v - P[v]) {
            nxv.push_back(it1->second);
            it1--;
        }
        auto it2 = Set2.lower_bound({v + P[v], v});
        while (it2->first == v + P[v]) {
            nxv.push_back(it2->second);
            it2++;
        }
        for (auto &nx : nxv) {
            if (seen[nx] == 0) {
                seen[nx] = 1;
                que.push(nx);
                Set1.erase({nx + P[nx], nx});
                Set2.erase({nx - P[nx], nx});
            }
        }
    }
    int ans = 0;
    rep(i, N) if (seen[i]) ans = i;
    cout << ans << '\n';
    return 0;
}

/**
 * Fの制約強化版(pairの数に制限がない)
 * 本来はペアを全列挙してその間に辺を張ってBFSやUnionFindで連結判定を行っていたが
 * 頂点0から辺を張り「ながら」BFSし、到達した点に対応する{Ai+i,i}と{j-Aj,j}を消していけば良い
 * 追記:これ多分O(N^2)のままです
 * BFSではなくDFSなどにして、「行けると判明した点にすぐに行く」ようにしないとダメそう
 * 直しました
 * N=1000000でペア数O(N^2)に対して動作することを確認
 */
