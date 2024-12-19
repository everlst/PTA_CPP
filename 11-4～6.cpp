#include <bits/stdc++.h>
using namespace std;

int n, key;
int val;

struct Node {
    int key;
    Node *left, *right;
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

Node* Insert(Node* root, int key) {
    if (root == NULL) {
        root = new Node(key);
    } else if (key < root->key) {
        root->left = Insert(root->left, key);
    } else {
        root->right = Insert(root->right, key);
    }
    return root;
}

bool Search(Node* root, int key) {
    if (root == NULL) {
        return false;
    } else if (root->key == key) {
        return true;
    } else if (key < root->key) {
        return Search(root->left, key);
    } else {
        return Search(root->right, key);
    }
}

Node* Delete(Node* root, int key, bool& found) {
    if (!root) {
        found = false;
        return NULL;
    }
    if (key < root->key) {
        root->left = Delete(root->left, key, found);  // 在之后删除了节点后，需要更新父节点的子树信息，也就是下面返回的临时节点
    } else if (key > root->key) {
        root->right = Delete(root->right, key, found);
    } else {
        found = true;
        if (!root->left) {
            Node* tmp = root->right;
            delete root;
            return tmp;  // 将临时节点返回给父节点
        } else if (!root->right) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        } else {
            Node* tmp = root->right;  // 当待删除节点既有左子树又有右子树时，找到右子树中的最小节点，其一定没有左子树，且大于待删除节点的左子树中的所有节点，小于待删除节点右子树中的所有节点
            while (tmp->left)
                tmp = tmp->left;
            root->key = tmp->key;
            root->right = Delete(root->right, tmp->key, found);
        }
    }
    return root;
}

int main() {
    cin >> n;
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        cin >> val;
        root = Insert(root, val);
    }

    cin >> key;

    // 第一次查找
    if (Search(root, key))
        cout << "Found key = " << key << endl;
    else
        cout << "NotFound." << endl;

    // 删除节点
    bool found = false;
    root = Delete(root, key, found);
    if (!found)
        cout << "错误：" << key << "不在树中。" << endl;

    // 第二次查找
    if (Search(root, key))
        cout << "Found key = " << key << endl;
    else
        cout << "NotFound." << endl;

    return 0;
}