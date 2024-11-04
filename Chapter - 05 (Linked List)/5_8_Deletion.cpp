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
void insertAtHead(Node *&head, int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
void deleteNode(Node *&head, int n) {
    Node *tmp = head;
    if (head == nullptr){
        cout << "UNDERFLOW!";
        return;
    }
    while (tmp->next->data != n){
        tmp = tmp->next;
        if (tmp->next == nullptr){
            cout << "Item doesn't exist;";
            return;
        }
    }
    tmp->next = tmp->next->next;
}

void displayList(Node *head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node *head = nullptr;
    
    insertAtHead(head, 8);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    
    cout << "Before deleting: ";
    displayList(head);
    
    cout << "Enter the value of the node to delete:\n";
    int n;
    cin >> n;
    
    deleteNode(head, n);
    cout << "\nAfter deleting: ";
    displayList(head);
    
    return 0;
}
