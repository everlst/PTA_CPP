#include <bits/stdc++.h>
using namespace std;

int a[1000];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    for (int i = 1; i <= n; i++) {
        if (m == a[i]) {
            cout << a[i] << endl;
            return 0;
        }
    }

    cout << m << " δ�ҵ���" << endl;

    return 0;
}