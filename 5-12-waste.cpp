#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val = -1;
    bool flag = 0;
    Node* left;
    Node* right;
    Node* father;
};

Node* root;
Node* head = nullptr;

Node* build_root(int v) {
    Node* newnode = new Node();
    newnode->val = v;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

Node* build(int v, Node* r) {
    Node* newnode = new Node();

    if (r->left != nullptr && r->right != nullptr) {
        build(v, r->father);
    }

    if (r->left != nullptr) {
        Node* newnode = new Node();
        newnode->val = v;
        newnode->flag = 1;
        newnode->father = r;
        r->right = newnode;
        return newnode;
    } else {
        Node* newnode = new Node();
        newnode->val = v;
        newnode->flag = 1;
        newnode->father = r;
        r->left = newnode;
        return newnode;
    }
}

void mark(Node* pt) {
    if (pt->left != nullptr) {
        Node* newnode = new Node();
        newnode->flag = 1;
        newnode->father = pt;
        pt->right = newnode;
    } else {
        Node* newnode = new Node();
        newnode->flag = 1;
        newnode->father = pt;
        pt->left = newnode;
    }
}

void Run() {
}

int main() {
    int n;
    cin >> n;

    int rt;
    cin >> rt;

    root = build_root(rt);
    head = root;

    for (int i = 2; i <= n; i++) {
        char c;
        cin >> c;
        if (c != '#') {
            int x = c - '0';
            head=build(x, head);
        } else {
            mark(head->father);
        }
    }

    cout << root->left->left->val << endl;

    return 0;
}