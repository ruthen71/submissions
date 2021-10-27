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

// using mint = modint998244353;
// using mint = modint1000000007;

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

int main() {
    ll N, K, T, U, V, L;
    cin >> N >> K >> T >> U >> V >> L;
    vll D(N);
    rep(N) cin >> D[i];
    vii ca(L + 1, 0);
    rep(i, N) ca[D[i]] = 1;
    vector<ld> dp(L + 1);
    dp[0] = 0;
    int ef = 0;  // ニンジンの効果が切れる位置
    int st = 0;  // ニンジンのストック
    rep(i, L) {
        // i->i+1へ移動
        if (ca[i]) {
            // ニンジンを拾える
            if (ef <= i) {  // 加速してない
                ef = i + T * V;
            } else if (st < K) {  // 加速しており、ストックできる
                st++;
            } else {  // 加速しており、ストックできない
                ef = i + T * V;
            }
        } else {
            // ニンジンを拾えない
            if (ef <= i) {     // 加速してない
                if (st > 0) {  // 加速できる
                    ef = i + T * V;
                    st--;
                }
            }
        }
        if (ef > i)
            dp[i + 1] = dp[i] + (ld)1 / V;
        else
            dp[i + 1] = dp[i] + (ld)1 / U;
    }
    show(dp);
    printf("%.15Lf\n", dp[L]);
    /*
    ll K2 = K + 1;
    V2<pair<ll, ld>> g((L + 1) * K2);
    rep(i, L) {
        rep(j, K + 1) {
            if (ca[i]) {
                // ニンジンを食べる
                g[i * K2 + j].pb(make_pair(min(L, i + T * v) * K2 + j, T));
                if (j < K) {
                    // ニンジンを食べない
                    g[i * K2 + j].pb(make_pair((i + 1) * K2 + j + 1, (ld)1 / U));
                }
            } else {
                if (j > 0) {
                    // ニンジンを食べる
                    g[i * K2 + j].pb(make_pair(min(L, i + T * v) * K2 + j - 1, T));
                }
                // ニンジンを食べない
                g[i * K2 + j].pb(make_pair((i + 1) * K2 + j, (ld)1 / U));
            }
        }
    }
    ll V = (L + 1) * (K + 1);
    vector<ld> dist(V, INF);
    dist[0] = 0;
    priority_queue<pair<ld, int>, vector<pair<ld, int>>, greater<pair<ld, int>>> que;
    que.push({0, 0});
    while (!que.empty()) {
        pair<ld, int> p = que.top();
        que.pop();
        int v = p.second;
        if (dist[v] < p.first) continue;
        for (auto edge : g[v]) {
            if (chmin(dist[edge.fi], dist[v] + edge.se)) {
                que.push(make_pair(dist[edge.fi], edge.fi));
            }
        }
    }
    ld ans = INF;
    rep(i, K2) chmin(ans, dist[L * K2 + i]);
    printf("%.10Lf\n", ans);
    */
    return 0;
}

/*
メモ
解説AC
頂点を増やしてダイクストラすると思ったが、
辺の数が多すぎる
解けなかった

戦略が結構簡単に(貪欲に)決まる
区間幅1の移動で考える(時間以外は整数で扱えるため)
ニンジンをゲットしたときに使うか
・現在加速していない->使う
・加速しており、まだストックできる->使わない
・加速しており、ストックできない->使う
使ってるときには1/Vの時間で進む
使ってない時には1/Uの時間で進む
加速がいつまでかを変数で持つ
*/
