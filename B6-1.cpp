#include <bits/stdc++.h>
using namespace std;

int n, m, a, h[10009];

void Sort(int x) {
    while (x > 1 && h[x] < h[x / 2]) {
        swap(h[x], h[x / 2]);
        x /= 2;
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = 1; i <= n; i++) {
        Sort(i);
    }

    for(int i=1; i<=m; i++) {
        cin >> a;
        for(; a; a /= 2) {
            cout << h[a] << (a == 1 ? "" : " ");
        }
        if(i != m) cout << endl;
    }

    return 0;
}