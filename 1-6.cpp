#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    long long sum = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum += i * j;
        }
    }

    cout << sum << endl;

    return 0;
}