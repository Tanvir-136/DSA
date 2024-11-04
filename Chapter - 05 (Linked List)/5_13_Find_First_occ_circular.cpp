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
        cout << tail->data << "->";
        tail = tail->next;
    }
    cout << endl;
}

void searchNode(Node *tail, int key, Node *head) {
    while (tail->next != head) {
        if (tail->next->data == key) {
            cout << "Found\nLocation is: " << tail->next << endl;
            return;
        }
        else if (tail->data == key) {
            cout << "This is the first element of the list." << endl;
            return;
        }
        tail = tail->next;
    }
    cout << "Not found" << endl;
}

int main() {
    Node *tail = nullptr;
    Node *head = tail;
    
    insertAtTail(tail, 1, head);
    insertAtTail(tail, 4, head);
    insertAtTail(tail, 5, head);
    insertAtTail(tail, 8, head);
    
    displayList(tail, head);
    
    cout << "Enter the node to be found: ";
    int value;
    cin >> value;
    searchNode(tail, value, head);
    
    return 0;
}
