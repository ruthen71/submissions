#include <bits/stdc++.h>
using namespace std;

// ref:https://ei1333.github.io/library/string/rolling-hash.cpp
struct RollingHash {
    static const uint64_t mod = (1ull << 61ull) - 1;
    using uint128_t = __uint128_t;
    vector<uint64_t> power;
    const uint64_t base;

    static inline uint64_t add(uint64_t a, uint64_t b) {
        if ((a += b) >= mod) a -= mod;
        return a;
    }

    static inline uint64_t mul(uint64_t a, uint64_t b) {
        uint128_t c = (uint128_t)a * b;
        return add(c >> 61, c & mod);
    }

    static inline uint64_t generate_base() {
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<uint64_t> rand(1, RollingHash::mod - 1);
        return rand(mt);
    }

    inline void expand(size_t sz) {
        if (power.size() < sz + 1) {
            int pre_sz = (int)power.size();
            power.resize(sz + 1);
            for (int i = pre_sz - 1; i < sz; i++) {
                power[i + 1] = mul(power[i], base);
            }
        }
    }

    explicit RollingHash(uint64_t base = generate_base()) : base(base), power{1} {}

    vector<uint64_t> build(const string &s) const {
        int sz = s.size();
        vector<uint64_t> hashed(sz + 1);
        for (int i = 0; i < sz; i++) {
            hashed[i + 1] = add(mul(hashed[i], base), s[i]);
        }
        return hashed;
    }

    template <typename T>
    vector<uint64_t> build(const vector<T> &s) const {
        int sz = s.size();
        vector<uint64_t> hashed(sz + 1);
        for (int i = 0; i < sz; i++) {
            hashed[i + 1] = add(mul(hashed[i], base), s[i]);
        }
        return hashed;
    }

    uint64_t query(const vector<uint64_t> &s, int l, int r) {
        expand(r - l);
        return add(s[r], mod - mul(s[l], power[r - l]));
    }

    uint64_t combine(uint64_t h1, uint64_t h2, size_t h2len) {
        expand(h2len);
        return add(mul(h1, power[h2len]), h2);
    }

    int lcp(const vector<uint64_t> &a, int l1, int r1, const vector<uint64_t> &b, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int low = 0, high = len + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))
                low = mid;
            else
                high = mid;
        }
        return low;
    }
};

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S, T;
    cin >> S >> T;
    int N = S.size(), M = T.size();
    int ans = 0;
    string S2 = S + S + S;
    while (S2.size() <= 3 * M) S2 += S;
    int N2 = S2.size();
    RollingHash roll;
    auto rh1 = roll.build(S2);
    auto rh2 = roll.build(T);
    vector<int> seen(N2, 0);
    for (int i = 0; i < N; i++) {
        if (seen[i]) continue;
        if (roll.query(rh1, i, i + M) == roll.query(rh2, 0, M)) {
            seen[i] = 1;
            int cur = 1, ind = i + M;
            while (ind + M < N2 && roll.query(rh1, ind, ind + M) == roll.query(rh2, 0, M)) {
                seen[ind] = 1;
                ind += M;
                cur++;
            }
            ans = max(ans, cur);
        }
    }
    if (M * ans > 2 * N) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}

/**
 * ローリングハッシュ
 * Rolling Hash
 * 適当にSを伸ばしてロリハしたら通った
 * (この解法の正当性はわかっていない)
 * 模範解答みたいにグラフで考えると良さそう
 * ダブリングを使った解↓
 * https://atcoder.jp/contests/abc135/submissions/28192808
 * というか閉路検出できれば良いのでUnionFindなりトポロジカルソートなりでOK
 *
 */