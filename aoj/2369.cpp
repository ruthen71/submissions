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
const ll dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const ll dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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

int dfs(string &s, int n, int l, int &r) {
    // sのl文字目からを評価する
    // 最終的にCATとなる部分がs[l,r)のときのrを返す
    if (s[l] != 'm') {
        r = l;
        return 0;
    }
    // s[l] = 'm'
    if (s[l + 1] == 'e') {
        // m + "" + e + CAT + w が確定
        // CAT が e から始まることはないため
        if (s[l + 2] == 'w') {
            // m + "" + e + "" + w が確定
            // CAT が w から始まることはないため
            r = l + 3;
            return 1;
        }
        // CATを評価
        int rr;
        int res = dfs(s, n, l + 2, rr);
        r = rr + 1;
        if (res && s[rr] == 'w') return 1;
        return 0;
    }
    if (s[l + 1] == 'w') {
        r = l + 2;
        return 0;
    }
    int rr;
    int res = dfs(s, n, l + 1, rr);
    if (s[rr] != 'e' || res == 0) {
        r = rr + 1;
        return 0;
    }
    if (res && s[rr + 1] == 'w') {
        r = rr + 2;
        return 1;
    }
    int rrr;
    int res2 = dfs(s, n, rr + 1, rrr);
    r = rrr + 1;
    if (s[rrr] != 'w' || res2 == 0) {
        return 0;
    }
    return 1;
}

int is_cat(string &s, int n) {
    int l = 0, r;
    int ret = dfs(s, n, l, r);
    if (r != n) return 0;
    return ret;
}

int main() {
    string s;
    cin >> s;
    int n = sz(s);
    int ans = is_cat(s, n);
    cout << (ans ? "Cat" : "Rabbit") << endl;
    return 0;
}

/*
メモ
構文解析
mew
CAT
猫
構文解析典型
・文字列長を気にする
・左右からはさんでいく
・メモ化再帰(s[l,r)が正しい文字列か否か)
*/
