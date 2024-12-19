#include <bits/stdc++.h>
using namespace std;

int n, rt, cnt, a[100], b[100], s[100];
char A[100], B[100];
int leftson[100], rightson[100];

void build(int x, int l, int r) {  // 按照前序遍历特点，先建立左子树，再建立右子树
    if (s[x] - 1 >= l)             // 如果左儿子存在
        leftson[x] = a[++cnt], build(a[cnt], l, s[x] - 1);
    if (s[x] + 1 <= r)  // 如果右儿子存在
        rightson[x] = a[++cnt], build(a[cnt], s[x] + 1, r);
    return;
}

int Dfs(int x, int dp) {
    if (!x)
        return 0;
    int m = dp;
    m = max(m, max(Dfs(leftson[x], dp + 1), Dfs(rightson[x], dp + 1)));
    return m;
}

int main() {
    cin >> n >> A >> B;
    for (int i = 0; i < n; i++) {
        a[i] = (A[i] >= 'a' && A[i] <= 'z' ? A[i] - 'a' + 1 : A[i] - 'A' + 27);
    }
    for (int i = 0; i < n; i++) {
        b[i] = (B[i] >= 'a' && B[i] <= 'z' ? B[i] - 'a' + 1 : B[i] - 'A' + 27);
    }

    for (int i = 0; i < n; i++) s[b[i]] = i;  // 中序遍历编号，以在重建二叉树时判断左右儿子
    rt = a[0];                                // 根节点
    cnt = 0;                                  // 实现在重建时在前序遍历序列中挨个查询
    build(rt, 0, n - 1);
    cout << Dfs(rt, 1) << endl;
    return 0;
}
