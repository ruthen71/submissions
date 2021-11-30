#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

struct UnionFind {
    vector<int> parents;
    UnionFind() {}
    UnionFind(int n) : parents(n, -1) {}
    int leader(int x) {
        if (parents[x] < 0)
            return x;
        else
            return parents[x] = leader(parents[x]);
    }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        if (parents[x] > parents[y]) swap(x, y);
        parents[x] += parents[y];
        parents[y] = x;
        return true;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    int size(int x) { return -parents[leader(x)]; }
    void init(int n) { parents.assign(n, -1); }  // reset
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    vector<vector<int>> es(N);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
        es[min(A[i], B[i])].push_back(i);
    }
    UnionFind uf(N);
    vector<int> ans(N, -1);
    int s = N;
    for (int i = N - 1; i >= 0; i--) {
        ans[i] = i + 1 - s;
        for (auto j : es[i]) {
            if (!uf.same(A[j], B[j])) {
                uf.merge(A[j], B[j]);
                s--;
            }
        }
    }
    for (auto ansi : ans) {
        cout << -ansi << '\n';
    }
    return 0;
}

/**
 * 辺の削除クエリ
 * 逆から見る
 */