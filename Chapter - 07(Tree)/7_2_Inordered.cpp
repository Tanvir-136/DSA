#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree *leftChild;
    BinaryTree *rightChild;

    BinaryTree(int data) {
        value = data;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

void inOrderTraversal(BinaryTree *node) {
    if (node == nullptr)
        return;

    inOrderTraversal(node->leftChild);
    cout << node->value << " ";
    inOrderTraversal(node->rightChild);
}

int main() {
    BinaryTree *root = new BinaryTree(2);
    root->leftChild = new BinaryTree(3);
    root->rightChild = new BinaryTree(4);
    root->leftChild->leftChild = new BinaryTree(5);
    root->leftChild->rightChild = new BinaryTree(6);
    root->rightChild->leftChild = new BinaryTree(5);
    root->rightChild->rightChild = new BinaryTree(6);

    inOrderTraversal(root);

    return 0;
}
