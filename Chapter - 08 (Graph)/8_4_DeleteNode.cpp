#include <iostream>
using namespace std;

struct Node {
    int data;     
    Node* next;   
};

// Function to insert a new node at the beginning (used for testing)
void insert(Node*& start, int item) {
    Node* newNode = new Node();
    newNode->data = item;
    newNode->next = start;
    start = newNode;
}

// Function to delete the first occurrence of ITEM in the list
void deleteNode(Node*& start, int item, bool& flag) {
    flag = false;  
    if (start == nullptr) {  // Step 1: If the list is empty
        return;
    }

    // Step 2: Check if the first node contains the ITEM
    if (start->data == item) {
        Node* ptr = start;         // Pointer to the first node
        start = start->next;       // Move START to the next node
        delete ptr;                // Free the deleted node
        flag = true;               // Set FLAG as true (item deleted)
        return;
    }

    // Step 3: Initialize PTR and SAVE
    Node* save = start;       // SAVE points to the node before the target
    Node* ptr = start->next;  // PTR points to the next node

    // Step 4: Loop through the list
    while (ptr != nullptr) {
        // Step 5: Check if PTR node contains ITEM
        if (ptr->data == item) {
            save->next = ptr->next;  // Remove the PTR node from the list
            delete ptr;               // Free the deleted node
            flag = true;              // Set FLAG as true (item deleted)
            return;
        }
        // Step 6: Update pointers to move forward
        save = ptr;
        ptr = ptr->next;
    }

    // Step 7: If ITEM is not found, FLAG remains FALSE
}
// Function to display the linked list
void display(Node* start) {
    Node* temp = start;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* start = nullptr;   // Initialize START as empty
    bool flag;

    // Insert some nodes for testing
    insert(start, 5);
    insert(start, 10);
    insert(start, 15);
    insert(start, 20);
    cout << "Original list: ";
    display(start);

    // Test deletion
    int itemToDelete = 15;
    deleteNode(start, itemToDelete, flag);
    if (flag) {
        cout << "Item " << itemToDelete << " deleted successfully.\n";
    } else {
        cout << "Item " << itemToDelete << " not found.\n";
    }

    cout << "Updated list: ";
    display(start);

    // Test deletion of an item not in the list
    itemToDelete = 100;
    deleteNode(start, itemToDelete, flag);
    if (flag) {
        cout << "Item " << itemToDelete << " deleted successfully.\n";
    } else {
        cout << "Item " << itemToDelete << " not found.\n";
    }

    cout << "Final list: ";
    display(start);

    return 0;
}