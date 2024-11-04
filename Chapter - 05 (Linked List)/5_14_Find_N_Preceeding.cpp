#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

void insertAtTail(Node *&tail, int value, Node *head) {
    Node *newNode = new Node(value);
    Node *current = tail;
    if (tail == nullptr) {
        tail = newNode;
        tail->next = head;
        return;
    }
    while (current->next != head)
        current = current->next;
    current->next = newNode;
    newNode->next = head;
}

void displayList(Node *tail, Node *head) {
    while (tail != head) {
        cout << tail->data << " -> ";
        tail = tail->next;
    }
    cout << endl;
}

void searchNode(Node *current, int key, Node *head) {
    while (current->next != head) {
        if (current->next->data == key) {
            cout << "Found node with value " << key << "\nLocation: " << current->next
                 << "\nPreceding node value: " << current->data << endl;
            return;
        } else if (current->data == key) {
            cout << "This is the first element in the list." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Node with value " << key << " not found." << endl;
}

int main() {
    Node *tail = nullptr;
    Node *head = tail;

    insertAtTail(tail, 1, head);
    insertAtTail(tail, 4, head);
    insertAtTail(tail, 5, head);
    insertAtTail(tail, 8, head);

    displayList(tail, head);

    cout << "Enter the node value to search: ";
    int searchValue;
    cin >> searchValue;
    searchNode(tail, searchValue, head);

    return 0;
}