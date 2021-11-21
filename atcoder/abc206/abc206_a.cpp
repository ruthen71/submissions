#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N;
    cin >> N;
    if (N * 108 / 100 < 206)
        puts("Yay!");
    else if (N * 108 / 100 == 206)
        puts("so-so");
    else
        puts(":(");
    return 0;
}
