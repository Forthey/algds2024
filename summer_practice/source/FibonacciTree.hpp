#pragma once
#include <memory>
#include <utility>
#include <list>


class FibonacciTree {
public:
    class Node;
private:
    std::shared_ptr<Node> root;

    void displayRec(std::shared_ptr<Node> const& node, std::size_t depth) const;
public:
    class Node {
    public:
        Node(int const value, std::shared_ptr<Node> parent) : value(value), parent(std::move(parent)) {}

        int value;

        int rank = 0;
//        bool isMarked = false;

        std::shared_ptr<Node> parent;
        std::list<std::shared_ptr<Node>> children;
    };

    explicit FibonacciTree(int const rootValue) {
        root = std::make_shared<Node>(rootValue, nullptr);
    }
    explicit FibonacciTree(std::shared_ptr<Node>& node) : root(node) {}

    [[nodiscard]] std::shared_ptr<Node> const& top() const { return root; }
    [[nodiscard]] std::shared_ptr<Node>& top() { return root; }

    void display() const;
};


using NodePointer = std::shared_ptr<FibonacciTree::Node> const&;
