#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    int left, right, val;
};

Vertex V[1005];
int c = 0;

int rec(string &A, int &ind) {
    int id = c++;
    ind++;  // 子の先頭
    if (A[ind] == ')') {
        V[id].left = -1;
        ind--;
    } else {
        V[id].left = rec(A, ind);
    }
    ind++;  // )
    ind++;  // [
    ind++;  // 数の始め
    int num = 0;
    while ('0' <= A[ind] && A[ind] <= '9') {
        num = 10 * num + A[ind++] - '0';
    }  // ]
    V[id].val = num;
    ind++;  // (
    ind++;  // 子の先頭
    if (A[ind] == ')') {
        V[id].right = -1;
        ind--;
    } else {
        V[id].right = rec(A, ind);
    }
    ind++;  // )
    return id;
}
void dfs(int ki1, int ki2) {
    // 通りがけに出力
    cout << "(";
    if (V[ki1].left != -1 && V[ki2].left != -1) {
        dfs(V[ki1].left, V[ki2].left);
    }
    cout << ")[" << V[ki1].val + V[ki2].val << "](";
    if (V[ki1].right != -1 && V[ki2].right != -1) {
        dfs(V[ki1].right, V[ki2].right);
    }
    cout << ")";
    return;
}

int main() {
    string A, B;
    cin >> A >> B;
    int i = 0, j = 0;
    int ki1 = rec(A, i);
    int ki2 = rec(B, j);
    dfs(ki1, ki2);
    cout << "\n";
    return 0;
}

/*
構文解析
rec()ができればdfs()は簡単
rec()の添え字合わせが大変
*/
