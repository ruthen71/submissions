#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ld EPS = 10e-10;

struct Point {
    ld x, y, z;
};

struct Circle {
    Point p;
    ld r;
};

ld distance(Point P, Point Q) { return sqrt((P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y) + (P.z - Q.z) * (P.z - Q.z)); }

int cross(Point S, Point G, Circle C) {
    Point V = {G.x - S.x, G.y - S.y, G.z - S.z};
    ld lb = 0, ub = 1;
    for (int t = 0; t < 100; t++) {
        ld d = ub - lb;
        ld l = lb + d / 3, r = lb + 2 * d / 3;
        Point lp = {S.x + l * V.x, S.y + l * V.y, S.z + l * V.z};
        Point rp = {S.x + r * V.x, S.y + r * V.y, S.z + r * V.z};
        if (distance(lp, C.p) > distance(rp, C.p))
            lb = l;
        else
            ub = r;
    }
    Point near = {S.x + lb * V.x, S.y + lb * V.y, S.z + lb * V.z};
    return (distance(near, C.p) <= C.r + EPS);
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<Circle> Cs(N);
    vector<ll> Ls(N);
    for (int i = 0; i < N; i++) {
        ld x, y, z, r;
        cin >> x >> y >> z >> r >> Ls[i];
        Cs[i] = {(Point){x, y, z}, r};
    }
    while (Q--) {
        Point S, G;
        cin >> S.x >> S.y >> S.z >> G.x >> G.y >> G.z;
        ll ret = 0;
        for (int i = 0; i < N; i++) {
            if (cross(S, G, Cs[i])) ret += Ls[i];
        }
        cout << ret << '\n';
    }
    return 0;
}

/*
円と線分の交差判定を三分探索で行う
V=G-Sとすると
P=S+tV(0<=t<=1)が線分
ところでこれを直線に拡大するとtの値に対して球の中心との距離は下に凸な関数になる
三分探索で極値を取るtを求め、それが[0,1]に入っているかで場合分けする
追記：実はlb=0,ub=1で良い(1次関数でも三分探索できる)
*/