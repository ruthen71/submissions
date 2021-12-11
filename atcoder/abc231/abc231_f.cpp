#include <bits/stdc++.h>
using namespace std;

#include <atcoder/fenwicktree>
using namespace atcoder;

using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    vector<ll> R = A;
    rep(i, N) R.push_back(B[i]);
    sort(ALL(R));
    R.erase(unique(ALL(R)), R.end());
    rep(i, N) A[i] = lower_bound(ALL(R), A[i]) - R.begin();
    rep(i, N) B[i] = lower_bound(ALL(R), B[i]) - R.begin();
    vector<pair<ll, ll>> AB(N);
    rep(i, N) AB[i] = {A[i], -B[i]};
    map<pair<ll, ll>, ll> mp;
    rep(i, N) mp[AB[i]]++;
    fenwick_tree<ll> fw(2 * N + 5);
    ll ans = 0;
    for (auto p : mp) {
        fw.add(-p.first.second, p.second);
        ans += fw.sum(-p.first.second, 2 * N + 5) * p.second;
    }
    cout << ans << '\n';
    return 0;
}

/**
 * Ai>=AjかつBi<=Bjとなるものの個数
 * まず座圧
 * 転倒数っぽくやる
 * (Ai,Bi)ごとにAiの小さい順にやる(重複分はmapを使ってまとめてやる)
 * Aiについて、もう見た値しかAi>=Ajになるようなjはない
 * よってBi<=Bjとなるjの個数が分かればOK
 * Aiが同じ時にはBiは大きい順に、fenwick tree などで管理してやるとOK
 */
