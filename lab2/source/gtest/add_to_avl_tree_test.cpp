#include <gtest/gtest.h>

extern "C" {
#include "rotate.h"
}

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


void printTree(AvlNode *root, int depth = 0) {
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


TEST(lab2, addToAvlTree_NULL_falseReturned) {
    // arrange
    bool expected = false;

    // act
    bool actual = addToAvlTree(nullptr, 0);

    // assert
    ASSERT_EQ(expected, actual);
}


TEST(lab2, addToAvlTree_emptyTree_validValReturned) {
    // arrange
    AvlNode *root = nullptr;
    int value = 1;
    AvlNode *expected = new AvlNode{1, nullptr, nullptr, nullptr, 0};

    // act
    addToAvlTree(&root, value);

    // assert
    ASSERT_EQ(*root, *expected);

    // clear
    clearAvlTree(&root);
    clearAvlTree(&expected);
    ASSERT_EQ(root, nullptr);
    ASSERT_EQ(expected, nullptr);
}


TEST(lab2, addToAvlTree_smallLeftRotate_validValReturned) {
    // arrange
    AvlNode *root = nullptr;
    addToAvlTree(&root, 2);
    addToAvlTree(&root, 1);
    addToAvlTree(&root, 4);
    addToAvlTree(&root, 3);
    addToAvlTree(&root, 5);
    int value = 6;

    auto *expected = new AvlNode{4, nullptr, nullptr, nullptr, 0};
    expected->left = new AvlNode{2, expected, nullptr, nullptr, 0};
    expected->left->left = new AvlNode{1, expected->left, nullptr, nullptr, 0};
    expected->left->right = new AvlNode{3, expected->left, nullptr, nullptr, 0};
    expected->right = new AvlNode{5, expected, nullptr, nullptr, -1};
    expected->right->right = new AvlNode{6, expected->right, nullptr, nullptr, 0};


    // act
    addToAvlTree(&root, value);

    // assert
    ASSERT_TRUE(*root == *expected);

    // clear
    clearAvlTree(&root);
    clearAvlTree(&expected);
    ASSERT_EQ(root, nullptr);
    ASSERT_EQ(expected, nullptr);
}


TEST(lab2, addToAvlTree_smallRightRotate_validValReturned) {
    // arrange
    AvlNode *root = nullptr;
    addToAvlTree(&root, 5);
    addToAvlTree(&root, 6);
    addToAvlTree(&root, 3);
    addToAvlTree(&root, 4);
    addToAvlTree(&root, 2);
    int value = 1;

    auto *expected = new AvlNode{3, nullptr, nullptr, nullptr, 0};
    expected->left = new AvlNode{2, expected, nullptr, nullptr, 1};
    expected->left->left = new AvlNode{1, expected->left, nullptr, nullptr, 0};
    expected->right = new AvlNode{5, expected, nullptr, nullptr, 0};
    expected->right->left = new AvlNode{4, expected->right, nullptr, nullptr, 0};
    expected->right->right = new AvlNode{6, expected->right, nullptr, nullptr, 0};


    // act
    addToAvlTree(&root, value);

    // assert
    ASSERT_TRUE(*root == *expected);

    // clear
    clearAvlTree(&root);
    clearAvlTree(&expected);
    ASSERT_EQ(root, nullptr);
    ASSERT_EQ(expected, nullptr);
}


TEST(lab2, addToAvlTree_bigLeftRotate_validValReturned) {
    // arrange
    AvlNode *root = nullptr;
    addToAvlTree(&root, 2);
    addToAvlTree(&root, 1);
    addToAvlTree(&root, 6);
    addToAvlTree(&root, 7);
    addToAvlTree(&root, 4);
    int value = 3;

    auto *expected = new AvlNode{4, nullptr, nullptr, nullptr, 0};
    expected->left = new AvlNode{2, expected, nullptr, nullptr, 0};
    expected->left->left = new AvlNode{1, expected->left, nullptr, nullptr, 0};
    expected->left->right = new AvlNode{3, expected->left, nullptr, nullptr, 0};
    expected->right = new AvlNode{6, expected, nullptr, nullptr, -1};
    expected->right->right = new AvlNode{7, expected->right, nullptr, nullptr, 0};


    // act
    addToAvlTree(&root, value);

    // assert
    ASSERT_TRUE(*root == *expected);

    // clear
    clearAvlTree(&root);
    clearAvlTree(&expected);
    ASSERT_EQ(root, nullptr);
    ASSERT_EQ(expected, nullptr);
}

TEST(lab2, addToAvlTree_bigRightRotate_validValReturned) {
    // arrange
    AvlNode *root = nullptr;
    addToAvlTree(&root, 5);
    addToAvlTree(&root, 2);
    addToAvlTree(&root, 6);
    addToAvlTree(&root, 1);
    addToAvlTree(&root, 3);
    int value = 4;

    auto *expected = new AvlNode{3, nullptr, nullptr, nullptr, 0};
    expected->left = new AvlNode{2, expected, nullptr, nullptr, 1};
    expected->left->left = new AvlNode{1, expected->left, nullptr, nullptr, 0};
    expected->right = new AvlNode{5, expected, nullptr, nullptr, 0};
    expected->right->left = new AvlNode{4, expected->right, nullptr, nullptr, 0};
    expected->right->right = new AvlNode{6, expected->right, nullptr, nullptr, 0};


    // act
    addToAvlTree(&root, value);

    // assert
    ASSERT_TRUE(*root == *expected);

    // clear
    clearAvlTree(&root);
    clearAvlTree(&expected);
    ASSERT_EQ(root, nullptr);
    ASSERT_EQ(expected, nullptr);
}
