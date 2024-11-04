#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtTail(Node *&head, int value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void displayList(Node *head) {
    Node *current = head;
    cout << "Forward traversal: ";
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node *head = nullptr;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    displayList(head);
    return 0;
}