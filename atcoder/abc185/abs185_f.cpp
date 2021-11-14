#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int op(int a, int b) { return a ^ b; }
int e() { return 0; }

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    segtree<int, op, e> seg(A);
    while (Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if (T == 1)
            seg.set(X - 1, seg.get(X - 1) ^ Y);
        else
            cout << seg.prod(X - 1, Y) << '\n';
    }
    return 0;
}

/*
セグメントツリー、セグ木、Segment Tree
セグ木でやる
*/