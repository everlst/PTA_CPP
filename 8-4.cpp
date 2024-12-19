#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
vector<pair<int, int> > e[105];
int dis[105], pre[105];
int ans;
bool flag[105];

void prim() {
    memset(dis, 0x3f, sizeof(dis));
    int tmp, x;
    dis[0] = 0;
    pre[0] = -1;
    for (int i = 0; i < n; i++) {
        tmp = INF + 1;  // 如果tmp不加1，那么当图不联通时，x就不会更新，dis[x]就一直是当前联通图的最后一个节点，并在循环内（i的循环）一直让“ans += dis[x];”，导致结果错误，不能判断图不联通。
        for (int j = 0; j < n; j++) {
            if (!flag[j] && dis[j] < tmp) {     //由于之前tmp初始化为INF+1，所以这里当图不联通时，也可以进入判断，并在下面使得 ans = -1 并退出循环。
                x = j;
                tmp = dis[j];
            }
        }
        flag[x] = true;
        if (dis[x] == INF) {
            ans = -1;
            break;
        }
        ans += dis[x];
        for (auto v : e[x]) {  // 遍历x的所有邻接点
            if (!flag[v.first] && dis[v.first] > v.second) {
                dis[v.first] = v.second;
                pre[v.first] = x;
            }
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    prim();

    printf("total weight = %d\n", ans);

    for (int i = 0; i < n; i++) {
        printf("%d ", pre[i]);
    }

    return 0;
}