#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll INF = 1ll << 60;

void solve(int N) {
    int M, S, G1, G2;
    cin >> M >> S >> G1 >> G2;
    S--, G1--, G2--;
    vector<vector<ll>> d1(N, vector<ll>(N, INF)), d2(N, vector<ll>(N, INF));
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d1[a][b] = c;
        d2[b][a] = c;
    }
    for (int i = 0; i < N; i++) d1[i][i] = 0, d2[i][i] = 0;
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
                d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i < N; i++) ans = min(ans, d1[S][i] + d2[G1][i] + d2[G2][i]);
    cout << ans << endl;
}

int main() {
    int N;
    while (cin >> N, N) solve(N);
    return 0;
}

/*
ワーシャルフロイドやる
*/