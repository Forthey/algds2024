#include "FibonacciTree.hpp"

#include <iostream>


void FibonacciTree::printNodeValue(const int value, const std::size_t depth, bool markNode) {
    for (std::size_t j = 0; j < depth; j++) {
        std::cout << "\t";
    }
    if (markNode) {
        std::cout << "--> ";
    }
    else {
        std::cout << "\t";
    }
    std::cout << value << std::endl;
}

void FibonacciTree::display() const {
    displayRec(root, 0ull, true);
}

void FibonacciTree::displayRec(const std::shared_ptr<Node> &node, std::size_t depth, bool markNode = false) {
    if (!node) {
        return;
    }

    if (node->children.empty()) {
        printNodeValue(node->value, depth, markNode);
        return;
    }

    std::size_t i = 0ull;
    bool isOddSize = node->children.size() % 2 != 0;
    for (auto childIter = node->children.rbegin(); childIter != node->children.rend(); childIter++) {
        if (i == node->children.size() / 2ull) {
            printNodeValue(node->value, depth, markNode);
        }
        displayRec(*childIter, depth + 1ull);
        i++;
    }
}
