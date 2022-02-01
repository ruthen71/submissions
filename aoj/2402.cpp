#include <bits/stdc++.h>
using namespace std;

// はじめに
using Double = double;
const Double EPS = 1e-8;
const Double PI = acos(-1);
inline int sign(const Double &x) { return x <= -EPS ? -1 : (x >= EPS ? 1 : 0); }
inline bool equals(const Double &a, const Double &b) { return sign(a - b) == 0; }
Double radian_to_degree(Double r) { return r * 180.0 / PI; }
Double degree_to_radian(Double d) { return d * PI / 180.0; }

// 点
using Point = complex<Double>;
// Point operator*(const Point &p, const Double &d) { return Point(p.real() * d, p.imag() * d); }  // 定数を掛ける
// Point operator/(const Point &p, const Double &d) { return Point(p.real() / d, p.imag() / d); }  // 定数で割る
istream &operator>>(istream &is, Point &p) {
    Double x, y;
    is >> x >> y;
    p = Point(x, y);
    return is;
}
Double dot(const Point &a, const Point &b) { return a.real() * b.real() + a.imag() * b.imag(); }    // 内積
Double cross(const Point &a, const Point &b) { return a.real() * b.imag() - a.imag() * b.real(); }  // 外積
// thetaだけ反時計回りに回転させる(thetaは弧度法なので、例えば90度回転させたいときにはtheta=PI/2とする)
Point rotate(const Point &p, const Double &theta) { return p * Point(cos(theta), sin(theta)); }

// 直線
struct Line {
    Point a, b;
    Line() = default;
    Line(Point a, Point b) : a(a), b(b) {}
    friend ostream &operator<<(ostream &os, const Line &p) { return os << p.a << "->" << p.b; }
    friend istream &operator>>(istream &is, Line &p) { return is >> p.a >> p.b; }
};

// 線分
struct Segment : Line {
    Segment() = default;
    Segment(Point a, Point b) : Line(a, b) {}
};

// 円
struct Circle {
    Point o;
    Double r;
    Circle() = default;
    Circle(Point o, Double r) : o(o), r(r) {}
    friend ostream &operator<<(ostream &os, const Circle &c) { return os << c.o << " " << c.r; }
    friend istream &operator>>(istream &is, Circle &c) { return is >> c.o >> c.r; }  // (x,y),rの順
};

// 射影(projection):CGL_1_A
// 直線lに点pから引いた垂線の足を求める
Point projection(const Line &l, const Point &p) {
    Double t = dot(p - l.a, l.b - l.a) / norm(l.b - l.a);
    return l.a + t * (l.b - l.a);
}

// 反射(reflection):CGL_1_B
// 直線lについて点pと線対称の点を求める
Point reflection(const Line &l, const Point &p) { return p + (projection(l, p) - p) * (Double)2.0; }

// 反時計回り(ccw):CGL_1_C
// 点a,b,cの位置関係を調べる(aを基準とする)
constexpr int COUNTER_CLOCKWISE = 1;  // a-b-cが反時計回り
constexpr int CLOCKWISE = -1;         // a-b-cが時計回り
constexpr int ONLINE_BACK = 2;        // c-a-b(一直線上)
constexpr int ONLINE_FRONT = -2;      // a-b-c(一直線上)
constexpr int ON_SEGMENT = 0;         // a-c-b(一直線上)
int ccw(const Point &a, Point b, Point c) {
    b = b - a, c = c - a;
    if (sign(cross(b, c)) == 1) return COUNTER_CLOCKWISE;
    if (sign(cross(b, c)) == -1) return CLOCKWISE;
    if (sign(dot(b, c)) == -1) return ONLINE_BACK;
    if (norm(b) < norm(c)) return ONLINE_FRONT;
    return ON_SEGMENT;
}

// 平行・垂直(parallel/orthogonal):CGL_2_A
// 2直線l1,l2が平行・垂直か判定する(それぞれ外積・内積が0)
bool is_parallel(const Line &l1, const Line &l2) { return sign(cross(l1.b - l1.a, l2.b - l2.a)) == 0; }
bool is_orthogonal(const Line &l1, const Line &l2) { return sign(dot(l1.b - l1.a, l2.b - l2.a)) == 0; }

// 交差判定(intersection):CGL_2_B
// 2線分s1,s2が交差するか判定する
bool intersection_ss(const Segment &s1, const Segment &s2) { return (ccw(s1.a, s1.b, s2.a) * ccw(s1.a, s1.b, s2.b) <= 0 && ccw(s2.a, s2.b, s1.a) * ccw(s2.a, s2.b, s1.b) <= 0); }
// 線分sと点pの場合(一応distance_spの実装でverify)
bool intersection_sp(const Segment &s, const Point &p) { return ccw(s.a, s.b, p) == ON_SEGMENT; }
// 直線lと点pの場合(absが1でない<=>ccwがONLINE_BACKかONLINE_FRONTかON_SEGMENT)(未verify)
bool intersection_lp(const Line &l, const Point &p) {
    int res = ccw(l.a, l.b, p);
    return (res == ONLINE_BACK || res == ONLINE_FRONT || res == ON_SEGMENT);
}
// 直線l1,l2の場合(未verify)
bool intersection_ll(const Line &l1, const Line &l2) {
    // cross_point_llの説明を参考に
    Point base = l1.b - l1.a;
    Double d12 = cross(base, l2.b - l2.a);
    Double d1 = cross(base, l1.b - l2.a);
    if (sign(d12) == 0 && sign(d1) == 0) return true;  // 一致
    // 平行か1点で交わるか
    return !is_parallel(l1, l2);
}

// 線分の交点(cross point):CGL_2_C
// 2直線l1,l2の交点を求める(未verify)
Point cross_point_ll(const Line &l1, const Line &l2) {
    // 2直線の関係:1点で交わるor平行or一致
    Point base = l1.b - l1.a;
    Double d12 = cross(base, l2.b - l2.a);
    Double d1 = cross(base, l1.b - l2.a);
    // 一致(sign(d12) == 0 は is_parallelと本質的に同じ, sign(d1) == 0は重なっているか)
    if (sign(d12) == 0 && sign(d1) == 0) return l2.a;  // 2直線が一致するので適当に点を返す
    assert(is_parallel(l1, l2) == false);              // assert(sign(d12) != 0);と同じ
    return l2.a + (l2.b - l2.a) * (d1 / d12);
}
// 2線分s1,s2の交点を求める
Point cross_point_ss(const Segment &s1, const Segment &s2) {
    assert(intersection_ss(s1, s2));  // 交点を持つかまず判定する
    // 1点で交わるor無数の点で交わる
    Point base = s1.b - s1.a;
    Double d12 = cross(base, s2.b - s2.a);
    Double d1 = cross(base, s1.b - s2.a);
    if (sign(d12) == 0 && sign(d1) == 0) {
        // 無数の点で交わる(未verify)
        if (intersection_sp(s1, s2.a)) return s2.a;
        if (intersection_sp(s1, s2.b)) return s2.b;
        if (intersection_sp(s2, s1.a)) return s1.a;
        assert(intersection_sp(s2, s1.b));
        return s1.b;
    }
    return s2.a + (s2.b - s2.a) * (d1 / d12);
}

// 距離(distance):CGL_2_D
// 2点a,bの距離を求める(未verify)
Double distance_pp(const Point &a, const Point &b) { return abs(a - b); }
// 直線lと点pの距離を求める(未verify)
Double distance_lp(const Line &l, const Point &p) { return abs(p - projection(l, p)); }
// 線分sと点pの距離を求める
Double distance_sp(const Segment &s, const Point &p) {
    Point r = projection(s, p);
    if (intersection_sp(s, r)) return abs(r - p);
    return min(abs(s.a - p), abs(s.b - p));
}
// 線分s1,s2の距離を求める
Double distance_ss(const Segment &s1, const Segment &s2) {
    if (intersection_ss(s1, s2)) return 0.0;
    return min({distance_sp(s1, s2.a), distance_sp(s1, s2.b), distance_sp(s2, s1.a), distance_sp(s2, s1.b)});
}

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

struct star5 {
    vector<Segment> Segs;
    Double x, y, deg, r;
    star5() {}
    star5(Double x, Double y, Double deg, Double r) : x(x), y(y), deg(deg), r(r) {
        Point a1 = polar(r, PI / 2 + degree_to_radian(deg));
        Point p = Point(x, y);
        for (int i = 0; i < 5; i++) {
            Point a2 = rotate(a1, degree_to_radian(144));
            Segs.push_back(Segment(a1 + p, a2 + p));
            a1 = a2;
        }
    }
};

Double distance_star5(const star5 &s1, const star5 &s2) {
    Double ret = numeric_limits<Double>::infinity();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ret = min(ret, distance_ss(s1.Segs[i], s2.Segs[j]));
        }
    }
    return ret;
}

const Double INF = numeric_limits<Double>::infinity();

void solve(int N, int M, int L) {
    M--, L--;
    vector<star5> S(N);
    rep(i, N) {
        Double x, y, a, r;
        cin >> x >> y >> a >> r;
        S[i] = star5(x, y, a, r);
    }
    vector<vector<Double>> dist(N, vector<Double>(N, INF));
    rep(i, N) rep(j, N) dist[i][j] = distance_star5(S[i], S[j]);
    rep(k, N) rep(i, N) rep(j, N) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    cout << fixed << setprecision(15) << dist[M][L] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, L;
    while (cin >> N >> M >> L, N) solve(N, M, L);
    return 0;
}

/**
 * Floyd-Warshall法
 * 五芒星を線分5本で表現する
 * 五芒星間の距離は、5*5=25ペアに対する線分同士の距離の最小値
 * あとはワーシャルフロイド法を使う
 */
