#include <bits/stdc++.h>
using namespace std;

// https://ei1333.github.io/luzhiled/snippets/string/rolling-hash.html

template <unsigned mod>
struct RollingHash {
    vector<unsigned> hashed, power;

    inline unsigned mul(unsigned a, unsigned b) const {
        unsigned long long x = (unsigned long long)a * b;
        unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
        asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod));
        return m;
    }

    RollingHash(const string &s, unsigned base = 10007) {
        int sz = (int)s.size();
        hashed.assign(sz + 1, 0);
        power.assign(sz + 1, 0);
        power[0] = 1;
        for (int i = 0; i < sz; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }

    unsigned get(int l, int r) const {
        unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if (ret >= mod) ret -= mod;
        return ret;
    }

    unsigned connect(unsigned h1, int h2, int h2len) const {
        unsigned ret = mul(h1, power[h2len]) + h2;
        if (ret >= mod) ret -= mod;
        return ret;
    }

    int LCP(const RollingHash<mod> &b, int l1, int r1, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (get(l1, l1 + mid) == b.get(l2, l2 + mid))
                low = mid;
            else
                high = mid;
        }
        return (low);
    }
};

using RH = RollingHash<1000000007>;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

void solve(string &pat) {
    string text;
    getline(cin, text);
    RH rh1(pat), rh2(text);
    int N = pat.size(), M = text.size();
    vector<int> ans;
    rep(i, M - N + 1) {
        if (rh1.get(0, N) == rh2.get(i, i + N)) {
            ans.push_back(i);
        }
    }
    int s = ans.size();
    rep(i, s) {
        if (i == s - 1)
            cout << ans[i];
        else
            cout << ans[i] << " ";
    }
    cout << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    while (getline(cin, S)) solve(S);
    return 0;
}

/**
 * ロリハでpatに対する一致判定をtextの全部に対して行う
 */