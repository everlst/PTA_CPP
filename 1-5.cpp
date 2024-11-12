#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long sum = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    for (int i = 1; i <= n * n; i++) {
        sum += i;
    }

    cout << sum << endl;

    return 0;
}