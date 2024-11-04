#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
void InsertAtHead(Node *&head, int val){
    Node *n = new Node(val);
    n->next = head;
    head = n;
}
void _delete(Node *&head, int n){
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

void Display(Node *head){
    while (head != nullptr){
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node *node = nullptr;
    InsertAtHead(node, 5);
    InsertAtHead(node, 5);
    InsertAtHead(node, 4);
    InsertAtHead(node, 4);
    InsertAtHead(node, 0);

    cout << "Before deleting: ";
    Display(node);
    cout << "Insert the node which to delete: ";
    int n;
    cin >> n;
    _delete(node, n);
    cout << endl;
    cout << "After deleting: ";
    Display(node);
    return 0;
}