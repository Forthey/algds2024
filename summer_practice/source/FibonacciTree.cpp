#include "FibonacciTree.hpp"

#include <iostream>


void FibonacciTree::display() const {
    displayRec(root, 0ull);
}

void FibonacciTree::displayRec(const std::shared_ptr<Node> &node, std::size_t depth) const {
    if (!node) {
        return;
    }

    if (node->children.empty()) {
        for (std::size_t j = 0; j < depth; j++) {
            std::cout << "\t";
        }
        std::cout << node->value << std::endl;
        return;
    }

    std::size_t i = 0ull;
    for (auto childIter = node->children.rbegin(); childIter != node->children.rend(); childIter++) {
        if (i == node->children.size() / 2ull) {
            for (std::size_t j = 0; j < depth; j++) {
                std::cout << "\t";
            }
            std::cout << node->value << std::endl;
        }
        displayRec(*childIter, depth + 1ull);
        i++;
    }
}
