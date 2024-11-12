#include <bits/stdc++.h>
using namespace std;

int n;

struct Node {
    int val;
    int father;
    int left;
    int right;
} a[100];

int v[100];

void build(int v, int num) {
    if (a[num].val == -2)
        return;
    if (a[a[num].left].val == 0) {
        a[a[num].left].val = v;
        return;
    } else {
        if (a[a[num].right].val == 0) {
            a[a[num].right].val = v;
            return;
        }
    }
    if (a[a[num].left].val != -2) {
        build(v, a[num].left);
    }
    if (a[a[num].right].val != -2) {
        build(v, a[num].right);
    }
}

void dfs(int p) {
    if (a[p].val == -2) {
        return;
    }

    cout << a[p].val << endl;

    if (a[p].left <= n) {
        dfs(a[p].left);
    }

    if (a[p].right <= n) {
        dfs(a[p].right);
    }
}

int main() {
    freopen("5-12.in", "r", stdin);
    char c;
    int x;

    cin >> n;
    // cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        if (c == '#')
            x = -2;
        else
            x = c - '0';

        v[i] = x;

        if (i >= 2) {
            a[i].father = i / 2;
        } else {
            a[i].father = 1;
        }
        a[i].left = 2 * i;
        a[i].right = 2 * i + 1;
    }

    a[1].val = v[1];
    int i = 2;
    while (i <= n) {
        build(v[i], 1);
        i++;
    }

    dfs(1);

    return 0;
}
