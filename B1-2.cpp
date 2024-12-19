#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[1000000];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int h = a[n] - m, t = a[n];
    int x = 0;
    int sum = 0;

    while (t >= a[1]) {
        int s = 0;
        for (int i = n; i >= 1; i--) {
            if (a[i] >= h) {
                s++;
            } else {
                break;
            }
        }
        if (s >= sum) {
            sum = s;
            x = h;
        }
        n--;
        t = a[n];
        h = a[n] - m;
    }

    cout << x << " " << sum << endl;

    return 0;
}