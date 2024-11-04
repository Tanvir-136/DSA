#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
void InsertAtHead(Node *&head, int val){
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
void find_node(Node *&head, int n){
    Node *tmp = head;
    if (head ->data==n){
        cout << "LOC = NULL;" << endl;
        return;
    }
    while (tmp->next->data != n){
        tmp = tmp->next;
        if (tmp->next == nullptr){
            cout << "Item doesn't exist;";
            return;
        }
    }
    cout << "Preceding node: " << tmp->data << endl;
    cout << "Location : " << tmp->next << endl;
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
    InsertAtHead(node, 8);
    InsertAtHead(node, 5);
    InsertAtHead(node, 4);
    InsertAtHead(node, 1);
    InsertAtHead(node, 0);
    Display(node);
    int n;
    cout << "Insert the node which loc to be found: ";
    cin >> n;
    cout << endl;
    find_node(node, n);
    return 0;
}