#include <bits/stdc++.h>
using namespace std;

// clang-format off
//#include <atcoder/modint>
//using namespace atcoder;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using vii = vector<int>;
using vll = vector<ll>;
using vdd = vector<ld>;
using vvii = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvdd = vector<vector<ld>>;
using vvvii = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<ll>>>;
using vvvdd = vector<vector<vector<ld>>>;
template<class T, class U> using P = pair<T, U>;
template<class T> using V1 = vector<T>;
template<class T> using V2 = vector<vector<T>>;
template<class T> using V3 = vector<vector<vector<T>>>;
template<class T> using pque = priority_queue<T, vector<T>, greater<T>>;
#define _overload3(_1, _2, _3, name, ...) name
#define rep1(n) for (ll i = 0; i < (n); i++)
#define rep2(i, n) for (ll i = 0; i < (n); i++)
#define rep3(i, a, b) for (ll i = (a); i < (b); i++)
#define rep(...) _overload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for (ll i = (n) - 1; i >= 0; i--)
#define rrep2(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define rrep3(i, a, b) for (ll i = (b) - 1; i >= (a); i--)
#define rrep(...) _overload3(__VA_ARGS__, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define popcnt(x) __builtin_popcountll(x)
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end());
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
const int inf = 1 << 30;
const ll INF = 1ll << 60;
const ld DINF = numeric_limits<ld>::infinity();
const ll mod = 1000000007;
//const ll mod = 998244353;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932;
//const ll dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const ll dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<typename T> T minV(const vector<T> &x) { return *min_element(all(x)); }
template<typename T> T maxV(const vector<T> &x) { return *max_element(all(x)); }
template<class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) { return os << "(" << p.fi << ", " << p.se << ")"; }
template<class T> ostream &operator<<(ostream &os, const vector<T> &v) { os << "[ "; for (auto &z : v) os << z << " "; os << "]"; return os; }
#ifdef _DEBUG
#define show(x) cout << #x << " = " << x << endl;
#else
#define show(x)
#endif
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll rem(ll a, ll b) { return (a % b + b) % b; }
// clang-format on

// modint(ac-library)
// using mint = modint998244353;
// using mint = modint1000000007;
// ostream &operator<<(ostream &os, const mint &p) { return os << p.val(); }

ll modpow(ll a, ll N, ll mod) {
    ll res = 1;
    // 例えば3=101(2)なので、下位bitから順に1ならa倍する
    while (N) {
        if (N & 1) res = res * a % mod;
        a = a * a % mod;
        N >>= 1;
    }
    return res;
}

struct edge {
    ll to, dis, com;
};

vector<ll> dijkstra(vector<vector<pair<ll, ll>>> &GRAPH, int V, int S) {
    vector<ll> dist(V, INF);
    dist[S] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.push({0, S});

    while (!que.empty()) {
        pair<ll, int> p = que.top();
        que.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (int i = 0; i < GRAPH[v].size(); i++) {
            pair<int, ll> edge = GRAPH[v][i];
            if (dist[edge.first] > dist[v] + edge.second) {
                dist[edge.first] = dist[v] + edge.second;
                que.push({dist[edge.first], edge.first});
            }
        }
    }
    return dist;
}

void solve(int N) {
    ll M, C, S, G;
    cin >> M >> C >> S >> G;
    S--, G--;
    V2<edge> g(N);
    rep(i, M) {
        ll x, y, d, c;
        cin >> x >> y >> d >> c;
        x--, y--;
        g[x].push_back({y, d, c});
        g[y].push_back({x, d, c});
    }
    vvll q(C), r(C);
    vii pp(C);
    rep(C) cin >> pp[i];
    rep(i, C) {
        int p = pp[i];
        rep(j, p - 1) {
            int qi;
            cin >> qi;
            q[i].push_back(qi);
        }
        rep(j, p) {
            int ri;
            cin >> ri;
            r[i].push_back(ri);
        }
    }
    // show(q) show(r);
    vvll f(C + 1, vll(100005, 0));
    rep(i, C) {
        // q[i], r[i]を使う
        rep(c, 100004) {
            int idx = upper_bound(all(q[i]), c) - q[i].begin();
            f[i + 1][c + 1] = f[i + 1][c] + r[i][idx];
        }
    }

    V2<pll> gg(N);
    rep(t, 1, C + 1) {
        vvll dist(N, vll(N, INF));
        rep(i, N) dist[i][i] = 0;
        rep(j, N) {
            for (auto &es : g[j]) {
                if (es.com == t) {
                    chmin(dist[j][es.to], es.dis);
                }
            }
        }
        rep(k, N) rep(i, N) rep(j, N) chmin(dist[i][j], dist[i][k] + dist[k][j]);
        show(dist);
        rep(i, N) rep(j, N) {
            if (i != j && dist[i][j] != INF) {
                int end = dist[i][j];
                ll costa = 0;
                if (end >= 100000) {
                    costa += (end - 100000) * r[t][sz(r[t]) - 1];
                    end = 100000;
                }
                costa += f[t][end];
                gg[i].push_back({j, costa});
            }
        }
    }
    vll cost = dijkstra(gg, N, S);
    cout << (cost[G] == INF ? -1 : cost[G]) << endl;
    return;
}

int main() {
    ll n;
    while (cin >> n, n) solve(n);
    return 0;
}

/*
路線ごとにワーシャルフロイド、連結成分の任意の頂点間の料金を計算
してからダイクストラ
*/
