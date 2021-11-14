#include <bits/stdc++.h>
using namespace std;

#include <atcoder/fenwicktree>
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); i++)

int MAX = 100005;

int main() {
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> g(MAX);
    rep(i, N) {
        int M;
        cin >> M;
        vector<pair<int, int>> vp(M);
        rep(j, M) cin >> vp[j].first >> vp[j].second;
        int id = 0;
        // 最も左下にある多角形の頂点はかならず+1になる
        rep(j, M) {
            if (vp[j].first < vp[id].first)
                id = j;
            else if (vp[j].first == vp[id].first && vp[j].second < vp[id].second)
                id = j;
        }
        rotate(vp.begin(), vp.begin() + id, vp.end());
        int cur = 1;
        // 各点について、+1と-1を繰り返す
        rep(j, M) {
            g[vp[j].first].push_back({vp[j].second, cur});
            cur *= -1;
        }
    }
    int Q;
    cin >> Q;
    vector<vector<pair<int, int>>> g2(MAX);
    rep(i, Q) {
        int x, y;
        cin >> x >> y;
        g2[x].push_back({y, i});
    }
    vector<int> ans(Q);
    fenwick_tree<int> fw(MAX);
    rep(x, MAX) {
        for (auto gi : g[x]) {
            fw.add(gi.first, gi.second);
        }
        for (auto gi : g2[x]) {
            ans[gi.second] = fw.sum(0, gi.first + 1);
        }
    }
    for (auto ansi : ans) {
        cout << ansi << "\n";
    }
    return 0;
}

/*
解説AC
二次元累積和、平面走査、セグメントツリー、区間和、クエリ先読み
セグメント木
もし座標が配列に乗る場合、二次元累積和を使えばOK
単純な多角形の場合、左下の頂点から始めて、頂点ごとに+1,-1,+1,...とする
しかし座標平面が配列に乗らない、ので
クエリ先読みしてx座標順にして平面走査する
*/
