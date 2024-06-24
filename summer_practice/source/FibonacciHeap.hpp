#pragma once
#include <list>

#include "FibonacciTree.hpp"


class FibonacciHeap {
    std::list<FibonacciTree>::iterator minValueIter;
    std::list<FibonacciTree> heap;
    std::size_t size = 0ull;

    void compress();
public:
    FibonacciHeap() { minValueIter = heap.end(); }

    NodePointer insert(int const x);
    FibonacciHeap& merge(FibonacciHeap& otherHeap);
    int removeMin();

    [[nodiscard]] bool empty() const { return size == 0ull; }
    [[nodiscard]] NodePointer getMin() const { return minValueIter->top(); }

    void display() const;
};
