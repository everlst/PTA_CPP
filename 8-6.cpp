#include <bits/stdc++.h>
using namespace std;

const int N = 105;
struct Edge {
    int to, w;
    Edge(int _to, int _w) : to(_to), w(_w) {}
};

vector<Edge> e[N];                // 邻接表存储图
vector<pair<int, int>> edges[N];  // 存储输入的边
int n, m;
int in[N], out[N];  // 入度、出度
int ve[N], vl[N];
vector<pair<int, int>> critical;

bool topoSort() {
    memset(ve, 0, sizeof(ve));
    queue<int> q;
    vector<int> inDegree = vector<int>(n);
    for (int i = 0; i < n; i++)
        inDegree[i] = in[i];

    // 将所有入度为0的点加入队列
    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            q.push(i);

    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (auto edge : e[u]) {
            int v = edge.to, w = edge.w;
            ve[v] = max(ve[v], ve[u] + w);  //找到最晚开始时间  
            if (--inDegree[v] == 0)
                q.push(v);
        }
    }
    return cnt == n;
}

void Find() {
    // 找到最大的ve值作为初始vl值
    int maxVe = 0;
    for (int i = 0; i < n; i++)
        if (out[i] == 0)  // 终点
            maxVe = max(maxVe, ve[i]);

    // 初始化vl数组
    fill(vl, vl + n, maxVe);

    // 从后向前计算最早开始时间
    for (int t = n - 1; t >= 0; t--) {
        for (int u = 0; u < n; u++) {
            for (auto edge : e[u]) {
                int v = edge.to, w = edge.w;
                vl[u] = min(vl[u], vl[v] - w);
            }
        }
    }

    // 找出关键活动
    critical.clear();
    for (int u = 0; u < n; u++) {
        for (int i = edges[u].size() - 1; i >= 0; i--) {
            int v = edges[u][i].first;
            int w = edges[u][i].second;
            if (ve[u] == vl[v] - w) {
                critical.push_back({u, v});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back(Edge(v, w));
        edges[u].push_back({v, w});
        in[v]++;
        out[u]++;
    }

    if (!topoSort()) {
        cout << "关键路径分析结果为 0" << endl;
        return 0;
    }

    Find();

    for (auto p : critical) {
        cout << "<" << p.first << ", " << p.second << ">" << endl;
    }
    cout << "关键路径分析结果为 1" << endl;

    return 0;
}