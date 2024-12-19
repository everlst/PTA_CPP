#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
    int s[105];
    bool operator==(const node &x) const {
        for (int i = 1; i <= n; i++)
            if (s[i] != x.s[i])
                return false;
        return true;
    }
} ans, Raw, now;

bool Judge_Insertion_Sort() {
    now = Raw;
    for (int i = 2; i <= n; i++) {
        sort(now.s + 1, now.s + 1 + i);
        if (now == ans) {
            printf("Insertion Sort\n");
            sort(now.s + 1, now.s + i + 2);
            for (int i = 1; i < n; i++) printf("%d ", now.s[i]);
            printf("%d", now.s[n]);
            return true;
        }
    }
    return false;
}

int cnt, tmp, l[105], r[105];

bool Judge_Merge_Sort() {
    now = Raw;
    cnt = n;                                       // 记录子区间数量，当n=1时，说明已经排序完成
    for (int i = 1; i <= n; i++) l[i] = r[i] = i;  // 初始化每个区间的左右端点，初始为n个独立的区间
    while (cnt != 1) {
        tmp = 0;
        for (int i = 1; i <= cnt; i += 2) {
            if (r[i] != n)
                sort(now.s + l[i], now.s + r[i + 1] + 1);
            l[++tmp] = l[i];  // 更新每个区间的左端点
            if (i == cnt)
                r[tmp] = r[i];
            else
                r[tmp] = r[i + 1];  // 更新每个区间的右端点
        }
        cnt = tmp;
        if (now == ans) {
            printf("Merge Sort\n");
            tmp = 0;
            for (int i = 1; i <= cnt; i += 2) {
                if (r[i] != n)
                    sort(now.s + l[i], now.s + r[i + 1] + 1);
                l[++tmp] = l[i];
                if (i == cnt)
                    r[tmp] = r[i];
                else
                    r[tmp] = r[i + 1];
            }
            for (int i = 1; i < n; i++) printf("%d ", now.s[i]);
            printf("%d", now.s[n]);
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> Raw.s[i];

    for (int i = 1; i <= n; i++)
        cin >> ans.s[i];

    if (!Judge_Insertion_Sort())
        Judge_Merge_Sort();

    return 0;
}