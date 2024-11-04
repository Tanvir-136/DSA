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

void postOrderTraversal(BinaryTree *node) {
    if (node == nullptr)
        return;

    postOrderTraversal(node->leftChild);
    postOrderTraversal(node->rightChild);
    cout << node->value << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    BinaryTree *root = new BinaryTree(2);
    root->leftChild = new BinaryTree(3);
    root->rightChild = new BinaryTree(4);
    root->leftChild->leftChild = new BinaryTree(5);
    root->leftChild->rightChild = new BinaryTree(6);
    root->rightChild->leftChild = new BinaryTree(5);
    root->rightChild->rightChild = new BinaryTree(6);

    postOrderTraversal(root);

    return 0;
}
