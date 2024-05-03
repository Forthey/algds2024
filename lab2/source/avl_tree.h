#pragma once
#include <stdbool.h>
#include <stdlib.h>


typedef struct AvlNode AvlNode;
struct AvlNode {
    int value;
    AvlNode *parent;
    AvlNode *left, *right;
    int diff;
};


bool addToAvlTree(AvlNode** root, int value);
bool delFromAvlTree(AvlNode** root, int value);
bool clearAvlTree(AvlNode** root);

void rotateLeft(AvlNode** node);
void rotateRight(AvlNode** node);
