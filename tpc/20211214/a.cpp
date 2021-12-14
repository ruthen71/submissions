#include <bits/stdc++.h>
using namespace std;

// Suffix Array, Longest Common Prefix Array
// ref:https://ei1333.github.io/luzhiled/snippets/string/suffix-array.html

struct SuffixArray {
    vector<int> SA;
    const string s;

    SuffixArray(const string &str) : s(str) {
        SA.resize(s.size());
        iota(begin(SA), end(SA), 0);
        sort(begin(SA), end(SA), [&](int a, int b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });
        vector<int> classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
        for (int len = 1; len < s.size(); len <<= 1) {
            for (int i = 0; i < s.size(); i++) {
                if (i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < s.size() && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {
                    classes[SA[i]] = classes[SA[i - 1]];
                } else {
                    classes[SA[i]] = i;
                }
            }
            iota(begin(cnt), end(cnt), 0);
            copy(begin(SA), end(SA), begin(c));
            for (int i = 0; i < s.size(); i++) {
                int s1 = c[i] - len;
                if (s1 >= 0) SA[cnt[classes[s1]]++] = s1;
            }
            classes.swap(c);
        }
    }

    int operator[](int k) const { return SA[k]; }

    size_t size() const { return s.size(); }

    bool lt_substr(const string &t, int si = 0, int ti = 0) {
        int sn = (int)s.size(), tn = (int)t.size();
        while (si < sn && ti < tn) {
            if (s[si] < t[ti]) return true;
            if (s[si] > t[ti]) return false;
            ++si, ++ti;
        }
        return si >= sn && ti < tn;
    }

    int lower_bound(const string &t) {
        int low = -1, high = (int)SA.size();
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (lt_substr(t, SA[mid]))
                low = mid;
            else
                high = mid;
        }
        return high;
    }

    pair<int, int> lower_upper_bound(string &t) {
        int idx = lower_bound(t);
        int low = idx - 1, high = (int)SA.size();
        t.back()++;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            if (lt_substr(t, SA[mid]))
                low = mid;
            else
                high = mid;
        }
        t.back()--;
        return {idx, high};
    }

    void output() {
        for (int i = 0; i < size(); i++) {
            cout << i << ": " << s.substr(SA[i]) << endl;
        }
    }
};

struct LongestCommonPrefixArray {
    const SuffixArray &SA;
    vector<int> LCP, rank;

    LongestCommonPrefixArray(const SuffixArray &SA) : SA(SA), LCP(SA.size()) {
        rank.resize(SA.size());
        for (int i = 0; i < SA.size(); i++) {
            rank[SA[i]] = i;
        }
        for (int i = 0, h = 0; i < SA.size(); i++) {
            if (rank[i] + 1 < SA.size()) {
                for (int j = SA[rank[i] + 1]; max(i, j) + h < SA.size() && SA.s[i + h] == SA.s[j + h]; ++h)
                    ;
                LCP[rank[i] + 1] = h;
                if (h > 0) --h;
            }
        }
    }

    int operator[](int k) const { return LCP[k]; }

    size_t size() const { return LCP.size(); }

    void output() {
        for (int i = 0; i < size(); i++) {
            cout << i << ": " << LCP[i] << " " << SA.s.substr(SA[i]) << endl;
        }
    }
};

int main() {
    int L;
    cin >> L;
    string S;
    cin >> S;
    SuffixArray sa(S);
    LongestCommonPrefixArray lcp(sa);
    int ans = 0;
    for (auto x : lcp.LCP) ans = max(ans, x);
    cout << ans << '\n';
    return 0;
}

/**
 * SA
 * LCP
 * 1つの文字列Sに2回以上出現する部分文字列の中で最も長いものの長さ
 * 蟻本p341にある
 * 高さ配列の最大値
 */
