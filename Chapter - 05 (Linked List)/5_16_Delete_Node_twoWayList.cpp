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

void deleteNode(Node *&head, int value) {
    Node *current = head;
    if (current == nullptr) {
        cout << "Underflow: List is empty." << endl;
        return;
    }
    while (current->data != value) {
        if (current->next == nullptr) {
            cout << "Item doesn't exist." << endl;
            return;
        }
        current = current->next;
    }
    if (current->next == nullptr) {
        current->prev->next = nullptr;
    } else if (current->prev == nullptr) {
        head = current->next;
        head->prev = nullptr;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    delete current;
}

void displayList(Node *head) {
    Node *current = head;
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

    cout << "List before deletion: ";
    displayList(head);

    int item;
    cout << "Enter the value to delete: ";
    cin >> item;
    deleteNode(head, item);

    cout << "List after deletion: ";
    displayList(head);

    return 0;
}
