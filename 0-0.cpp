#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, k, a, b, c;
    cin >> m >> n;
    //    a=min(m,l);
    //   b=max(m,n);

    if (m == 0 || n == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (k = 1; k <= min(m, n); k++) {
        if (m % k == 0 && n % k == 0) {
            c = k;
        }
    }
    cout << c << endl;
    return 0;
}
