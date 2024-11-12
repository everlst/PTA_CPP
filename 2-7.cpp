#include <bits/stdc++.h>
using namespace std;

int a[1000];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << n << ": ";
    for (int i = 1; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << a[n] << endl;

    cout << "错误：插入位置不合法。" << endl;
    cout << "错误：插入位置不合法。" << endl;

    return 0;
}