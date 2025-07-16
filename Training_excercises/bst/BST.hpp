#pragma once

#include <iostream>
#include <cstdlib>

using std:: cin;
using std:: cout;
using std:: endl;

class BST {
    private:
        struct node{
            int key;
            node* left;
            node *right;
    };
        node* root;
        void addLeafPrivate(int key, node* Ptr);
        void printInOrderPrivate(node* Ptr);

    public:
        BST();
        node* createLeaf(int key);
        void addLeaf(int key);
        void printInOrder();
};

