#include <bits/stdc++.h>
using namespace std;

// アルゴリズムロジックのサイトの実装では各ノードに対応する文字があったが
// オートマトンを考えると自然でないと判断し、辺に文字を割り当てた

template <int char_size, int start>
struct trie {
    struct trie_node {
        vector<int> child_id;   // 子ノードのid
        vector<int> string_id;  // ノードを通る文字列のid
        vector<int> accept_id;  // 受理状態の文字列のid
        trie_node() : child_id(char_size, -1) {}
    };
    vector<trie_node> nodes;
    trie() { nodes.push_back(trie_node()); }
    void insert(const string &word, int word_id) {
        int node_id = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            const int c = word[i] - start;
            if (nodes[node_id].child_id[c] == -1) {
                nodes[node_id].child_id[c] = (int)nodes.size();
                nodes.push_back(trie_node());
            }
            nodes[node_id].string_id.push_back(word_id);
            node_id = nodes[node_id].child_id[c];
        }
        nodes[node_id].string_id.push_back(word_id);
        nodes[node_id].accept_id.push_back(word_id);
    }
    void insert(const string &word) { insert(word, (int)nodes[0].string_id.size()); }
    vector<int> search(const string &word, bool prefix = false) {
        // prefix=trueだとwordがprefixとなる単語すべてが条件を満たすとして扱う
        // 条件を満たす文字列のidの集合(vector)を返す
        int node_id = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = word[i] - start;
            if (nodes[node_id].child_id[c] == -1) {
                return vector<int>();
            }
            node_id = nodes[node_id].child_id[c];
        }
        return (prefix) ? nodes[node_id].string_id : nodes[node_id].accept_id;
    }
    int size() { return ((int)nodes.size()); }                // node数を返す
    int count() { return ((int)nodes[0].string_id.size()); }  // 追加した文字列の個数を返す
};

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    int Q;
    cin >> Q;
    vector<string> T(Q);
    rep(i, Q) cin >> T[i];
    rep(i, N) S[i] += '{';
    rep(i, Q) T[i] += '{';
    trie<27, 'a'> tr;
    rep(i, N) tr.insert(S[i]);
    for (string &Ti : T) {
        vector<int> idv = tr.search(Ti);
        int id = ((idv.size() == 0) ? N : idv[0]);
        int ans = 0, node_id = 0;
        rep(i, Ti.size()) {
            ans += upper_bound(ALL(tr.nodes[node_id].string_id), id) - tr.nodes[node_id].string_id.begin();
            node_id = tr.nodes[node_id].child_id[Ti[i] - 'a'];
            if (node_id == -1) break;
        }
        cout << ans << '\n';
    }
    return 0;
}

/**
 * trie木
 * 各S,Tに終端記号(今回はasciiコードで'z'の次の'{'を採用している)
 * を加えると、各Tiについて、各Sjと何文字一致しているかの総和になる
 * 各ノードにそのノードを通る文字列番号をすべて保存しておく
 * 二分探索で何番目までの文字列を考慮すれば良いかわかる
 * あとは各ノードについて足せばOK
 */
