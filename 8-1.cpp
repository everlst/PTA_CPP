#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
vector< pair<int, int> > Edge[105];
bool flag[105];
int dis[105]; // dis[i]表示从起点到i的最短距离
int pre[105]; // pre[i]表示从起点到i的最短路径上i的前一个节点

void dijstra() {
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;
    pre[0] = -1;
    int tmp, x;
    for (int i = 0;i<n;i++) {
        tmp = INF+5;
        for (int j = 0;j<n;j++) {
            if (!flag[j] && dis[j] < tmp) {
                x = j;
                tmp = dis[j];
            }
        }
        flag[x] = true;
        for (auto v : Edge[x]) { // 遍历x的所有邻接点
            if (dis[v.first] > dis[x] + v.second) {
                dis[v.first] = dis[x] + v.second;
                pre[v.first] = x;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Edge[a].push_back(make_pair(b, c));
    }

    dijstra();

    for (int i = 0;i<n;i++) {
        printf("v[%d]: dist=%d, path=%d", i, dis[i], pre[i]);
        if (i != n - 1) {
            printf("\n");
        }
    }

    return 0;
}