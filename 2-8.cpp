#include <bits/stdc++.h>
using namespace std;

bool Flag = false;

struct Node {
    int value;
    Node* next;
};

Node* insertHead(Node* head, int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

Node* Delete(Node* head, int pos) {
    if (pos < 1) {
        Flag = false;
        return head;
    }

    Node* current = head;
    if (pos == 1) {
        head = head->next;
        delete current;
        Flag = true;
        return head;
    }

    Node* prev = nullptr;
    for (int i = 1; i < pos; i++) {
        prev = current;
        if (current == nullptr || current->next == nullptr) {
            Flag = false;
            return head;
        }
        current = current->next;
    }

    prev->next = current->next;
    delete current;
    Flag = true;
    return head;
}

int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    int s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        head = insertHead(head, s);  // 顺次插入表头
    }

    int pos;
    cin >> pos;

    head = Delete(head, pos);

    if (!Flag) {
        cout << "错误：删除位置不合法。" << endl;
    }

    if (getLength(head) == 0) {
        cout << 0 << ":" << endl;
        return 0;
    }

    cout << getLength(head) << ": ";

    Node* current = head;
    while (current != nullptr) {
        cout << current->value;
        if (current->next != nullptr) {
            cout << " ";
        }
        current = current->next;
    }

    cout << endl;

    return 0;
}
