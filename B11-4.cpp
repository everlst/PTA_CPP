#include <bits/stdc++.h>
using namespace std;

int n, p;
int Hash[100005];  // 散列表
int keys[1005];    // 存储待插入的关键字

int key;
int pos;

int main() {
    cin >> n >> p;

    memset(Hash, -1, sizeof(Hash));  // 初始化散列表，-1表示该位置为空，因为余数包含0，所以不用0表示空

    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    for (int i = 0; i < n; i++) {
        key = keys[i];
        pos = key % p;
        int index = pos;

        while (Hash[index] != -1 && Hash[index] != key) {  // 线性探测,如果该位置已经有元素了，且不是要插入的元素，就继续往后找，即在此判断该key值是否已经存在
            index = (index + 1) % p;
        }

        Hash[index] = key;
        cout << index;
        if (i != n - 1)
            cout << " ";
    }
    return 0;
}