#include<bits/stdc++.h>
using namespace std;
class BinaryTree{
public:
    int value;
    BinaryTree *leftChild;
    BinaryTree *rightChild;

    BinaryTree(int data){
        value = data;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};
void preOrderTraversal(BinaryTree *node){
    if(node == nullptr){
        return;
    }
    cout << node->value << ' ';
    preOrderTraversal(node->leftChild);
    preOrderTraversal(node->rightChild);
}
void inOrderTraversal(BinaryTree *node){
    if(node == nullptr){
        return;
    }
    inOrderTraversal(node->leftChild);
    cout<< node-> value << ' ';
    inOrderTraversal(node -> rightChild);
}

void postOrderTraversal(BinaryTree *node){
    if(node == nullptr){
        return;
    }
    postOrderTraversal(node-> leftChild);
    postOrderTraversal(node-> rightChild);
    cout << node->value << ' ';
}
int main(){
    BinaryTree *root = new BinaryTree(2);
    root->leftChild = new BinaryTree(3);
    root->rightChild = new BinaryTree(4);
    root->leftChild->leftChild = new BinaryTree(5);
    root->leftChild->rightChild = new BinaryTree(6);
    root->rightChild->leftChild = new BinaryTree(7);
    root->rightChild->rightChild = new BinaryTree(8);

    cout << "Pre Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}