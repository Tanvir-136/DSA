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
void insertAtTail(Node *&tail, int value, Node* head) {
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

void displayList(Node *tail, Node* head) {
    while (tail != head) {
        cout << tail->data << "->";
        tail = tail->next;
    }
    cout << endl;
}

int main() {
    Node *tail = nullptr;
    Node* head = tail;
    
    insertAtTail(tail, 1, head);
    insertAtTail(tail, 4, head);
    insertAtTail(tail, 5, head);
    insertAtTail(tail, 8, head);
    
    displayList(tail, head);
    
    return 0;
}