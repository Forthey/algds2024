#include "FibonacciHeap.hpp"

#include <vector>
#include <iostream>


NodePointer FibonacciHeap::insert(const int x) {
    heap.emplace_back(x);
    if (minValueIter == heap.end() || minValueIter->top()->value > x) {
        minValueIter = --heap.end();
    }
    size++;
    return heap.back().top();
}


FibonacciHeap &FibonacciHeap::merge(FibonacciHeap &otherHeap) {
    if (minValueIter != heap.end() && otherHeap.minValueIter != otherHeap.heap.end()) {
        if (otherHeap.minValueIter->top()->value < minValueIter->top()->value) {
            minValueIter = otherHeap.minValueIter;
        }
    }
    else if (minValueIter == heap.end()) {
        minValueIter = otherHeap.minValueIter;
    }
    heap.splice(heap.end(), otherHeap.heap);
    size += otherHeap.size;
    return *this;
}


int FibonacciHeap::removeMin() {
    if (minValueIter == heap.end()) {
        throw std::runtime_error("Cannot remove min element from an empty heap");
    }

    for (auto& child : minValueIter->top()->children) {
        heap.emplace_back(child);
    }

    int value = minValueIter->top()->value;
    if (minValueIter->top()->parent) {
        auto& parentChildren = minValueIter->top()->parent->children;
        for (auto parentChild = parentChildren.begin(); parentChild != parentChildren.end(); parentChild++) {
            if (*parentChild == minValueIter->top()) {
                parentChildren.erase(parentChild);
                break;
            }
        }
    }
    else {
        heap.erase(minValueIter);
        minValueIter = heap.end();
    }

    size--;
    compress();

    return value;
}


void FibonacciHeap::compress() {
    std::list<FibonacciTree> fakeList;
    std::vector<std::list<FibonacciTree>::iterator> trees(size + 1, fakeList.end());

    for (auto treeIter = heap.begin(); treeIter != heap.end(); treeIter++) {
        if (minValueIter == heap.end() || treeIter->top()->value < minValueIter->top()->value) {
            minValueIter = treeIter;
        }

        auto& treeRoot = treeIter->top();
        if (trees[treeRoot->rank] == fakeList.end()) {
            trees[treeRoot->rank] = treeIter;
        }
        else {
            while (true) {
                auto &placedTreeRoot = trees[treeRoot->rank]->top();
                if (treeRoot->value > placedTreeRoot->value) {
                    std::iter_swap(treeIter,  trees[treeRoot->rank]);
                }
                treeRoot->children.emplace_back(placedTreeRoot);

                heap.erase(trees[treeRoot->rank]);
                trees[treeRoot->rank] = fakeList.end();

                treeRoot->rank++;
                if (trees[treeRoot->rank] == fakeList.end()) {
                    trees[treeRoot->rank] = treeIter;
                    break;
                }
            }
        }
    }
}


void FibonacciHeap::display() const {
    for (auto& tree : heap) {
        std::cout << "--- Tree --- " << std::endl;
        tree.display();
    }
}
