#include "BST.hpp"
#include <cstdlib>

BST::BST() {
    root = NULL;
}

BST::node* BST::createLeaf(int key) {
    node* n = new node;
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

void BST::addLeaf(int key) {
    addLeafPrivate(key, root);
}

void BST::addLeafPrivate(int key, node* Ptr) {
    if(root == NULL) {
        root = createLeaf(key);
    }
    else if (key < Ptr->key) {
        if (Ptr->left != NULL) {
            addLeafPrivate(key, Ptr->left);
        }
        else {
            Ptr->left = createLeaf(key);
        }
    }
    else if (key > Ptr->key) {
        if (Ptr->right != NULL) {
            addLeafPrivate(key, Ptr->right);
        }
        else {
            Ptr->right = createLeaf(key);
        }
    }
    else {
        cout << "The key " << key << " has been added to the tree\n";
    }
}

void BST::printInOrder() {
    printInOrderPrivate(root);
}

// in-order traversal
// 1. go left
// 2. process current node
// 3. go right
void BST::printInOrderPrivate(node* Ptr) {
    if (root != NULL) {
        if (Ptr->left != NULL) {
            printInOrderPrivate(Ptr->left);
        }
        cout << Ptr->key << " ";
        if (Ptr->right != NULL) {
            printInOrderPrivate(Ptr->right);
        }
    }
    else {
        cout << "The tree is empty!";
    }
}