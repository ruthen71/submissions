#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int a, b;
    cin >> a >> b;
    if (a <= b && b <= 6 * a)
        puts("Yes");
    else
        puts("No");
    return 0;
}
