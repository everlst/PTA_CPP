#include <bits/stdc++.h>
using namespace std;

int n;
string a;

int judge(string a) {
    int len = a.length();
    int m = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == '#') {
            m = -1;
            return m;
        } else {
            if (a[i] == ' ') {
                continue;
            } else {
                m = (m << 3) + (m << 1) + a[i] - '0';
            }
        }
    }

    return m;
}

int main() {
    freopen("5-12.in", "r", stdin);
    cin >> n;
    while (n--) {
        cin >> a;
        int x = judge(a);
        if (x != -1)
            cout << x << "\n";
    }

    return 0;
}