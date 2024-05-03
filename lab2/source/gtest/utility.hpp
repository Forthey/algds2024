#pragma once
extern "C" {
#include "avl_tree.h"
}


void printTree(AvlNode *root, int depth = 0);
bool operator==(AvlNode const& tree1, AvlNode const& tree2);
