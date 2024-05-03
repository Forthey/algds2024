#include <gtest/gtest.h>

extern "C" {
#include "avl_tree.h"
}

#include "utility.hpp"


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
