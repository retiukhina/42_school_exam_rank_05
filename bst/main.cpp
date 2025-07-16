#include "BST.hpp"
#include <cstdlib>

// in-order traversal
// 1. go left
// 2. process current node
// 3. go right

int main() {
    int treeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
    BST myTree;

    cout << "Printing the tree before adding numbers\n";
    myTree.printInOrder();

    cout << "Printing the tree after adding numbers\n";
    for (int i = 0; i < 16; i++) {
        myTree.addLeaf(treeKeys[i]);
    }
    myTree.printInOrder();
    cout << endl;
}

