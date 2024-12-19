#include <bits/stdc++.h>
using namespace std;

int A, B, n, m;
int Map[15][15];
char ch[15];
int cnt = 0;

int main() {
    freopen("7-1_6.out", "w", stdout);
    
    cin >> A >> B;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> ch[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) Map[i][j] = B;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Map[a][b] = c;
    }
    cout << "邻接矩阵为：" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << Map[i][j] << " ";
        }
        cout << endl;
    }

    cout << "顶点数 = " << n << endl;

    int a, b;
    cin >> a >> b;
    cout << "<" << a << ", " << b << "> 的存在性 = " << (Map[a][b] != B) << endl;

    cin >> a >> b;
    cout << "<" << a << ", " << b << "> 的存在性 = " << (Map[a][b] != B) << endl;

    cin >> a;
    for (int i = 0; i < n; i++) {
        if (Map[a][i] != B) {
            cout << "顶点" << a << "的第一个邻接点 = " << i << endl;
            break;
        }
    }

    cin >> a >> b;
    Map[a][b] = B;
    cout << "<" << a << ", " << b << "> 的存在性 = " << 0 << endl;

    cin >> a;
    cout << "待删除的顶点信息为 " << ch[a] << endl;

    swap(ch[n - 1], ch[a]);

    for (int i = 0; i < n; i++) swap(Map[i][a], Map[i][n - 1]);
    for (int i = 0; i < n; i++) swap(Map[a][i], Map[n - 1][i]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (Map[i][j] != B)
                cnt++;
        }
    }

    cout << "当前顶点数 = " << n - 1 << endl;
    cout << "当前边数 = " << cnt << endl;

    for (int i = 0; i < n - 1; i++) cout << ch[i];
    cout << endl;

    cout << "邻接矩阵为：" << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << Map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}