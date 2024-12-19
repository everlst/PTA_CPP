#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> e[105];
char s[105][5];
int In[105];  // 入度统计
int ans[105];
queue<int> q;

bool Judge() {
    for (int i = 0; i < n; i++)
        if (!In[i])
            q.push(i);  // 将入度为0的点入队
    int now, cnt = 0;
    while (!q.empty()) {
        now = q.front();  // 取队首元素
        q.pop();
        ans[++cnt] = now;        // 记录已加入拓扑排序中的点
        for (auto v : e[now])    // 遍历当前点的所有出边
            if ((--In[v]) == 0)  // 将当前点的所有出边的入度减1，若入度为0则入队
                q.push(v);
    }
    return n == cnt;
}
// 如果有环，那么环上的点的入度永远不会为0，所以最后的cnt一定小于n，无法拓扑排序

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);  // a -> b
        In[b]++;
    }

    if (!Judge())
        cout << "该图拓扑序存在性为 0\nbalabala";
    else {
        cout << "该图拓扑序存在性为 1\n";
        for (int i = 1; i <= n; i++) cout << s[ans[i]] << " ";
    }

    return 0;
}