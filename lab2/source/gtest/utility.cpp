#include "utility.hpp"

#include <iostream>


bool operator==(AvlNode const& tree1, AvlNode const& tree2) {
    bool equal = tree1.value == tree2.value && tree1.diff == tree2.diff,
            equalLeft = true, equalRight = true;
    try {
        if (tree1.left != nullptr) {
            equalLeft = *tree1.left == *tree2.left;
        }
        if (tree1.right != nullptr) {
            equalRight = *tree1.right == *tree2.right;
        }
    }
    catch (std::exception &exception) {
        return false;
    }
    return equal && equalLeft && equalRight;
}


void printTree(AvlNode *root, int depth) {
    if (root == nullptr) {
        for (int i = 0; i < depth; i++) {
            std::cout << "\t\t";
        }
        std::cout << "n" << std::endl;
        return;
    }
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++) {
        std::cout << "\t\t";
    }
    std::cout << root->value << "d=" << root->diff << std::endl;
    printTree(root->left, depth + 1);
}