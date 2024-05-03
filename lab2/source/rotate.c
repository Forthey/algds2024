#include "avl_tree.h"


void smallRotateLeft(AvlNode** node) {
    if (*node == NULL) {
        return;
    }

    AvlNode* nodeR = (*node)->right;
    AvlNode* nodeRSub = nodeR->left;

    nodeR->parent = (*node)->parent;
    nodeR->left = *node;
    (*node)->parent = nodeR;

    (*node)->right = nodeRSub;
    if (nodeRSub != NULL) {
        nodeRSub->parent = *node;
    }

    *node = nodeR;
}

void smallRotateRight(AvlNode** node) {
    if (*node == NULL) {
        return;
    }

    AvlNode* nodeL = (*node)->left;
    AvlNode* nodeLSub = nodeL->right;

    nodeL->parent = (*node)->parent;
    nodeL->right = *node;
    (*node)->parent = nodeL;

    (*node)->left = nodeLSub;
    if (nodeLSub != NULL) {
        nodeLSub->parent = *node;
    }

    *node = nodeL;
}

void bigRotateLeft(AvlNode** node) {
    smallRotateRight(&(*node)->right);
    smallRotateLeft(node);
}

void bigRotateRight(AvlNode** node) {
    smallRotateLeft(&(*node)->left);
    smallRotateRight(node);
}


void rotateLeft(AvlNode** node) {
    switch ((*node)->right->diff) {
    case -1:
        smallRotateLeft(node);
        (*node)->diff = 0;
        if ((*node)->left != NULL) {
            (*node)->left->diff = 0;
        }
        break;
    case 0:
        smallRotateLeft(node);
        (*node)->diff = 1;
        if ((*node)->left != NULL) {
            (*node)->left->diff = -1;
        }
        break;
    case 1:
        bigRotateLeft(node);
        switch ((*node)->diff)
        {
        case 1:
            (*node)->left->diff = 0;
            (*node)->right->diff = -1;
            break;
        case -1:
            (*node)->left->diff = 1;
            (*node)->right->diff = 0;
            break;
        case 0:
            (*node)->left->diff = 0;
            (*node)->right->diff = 0;
            break;
        }
        (*node)->diff = 0;
        break;
    }
}


void rotateRight(AvlNode** node) {
    switch ((*node)->left->diff) {
        case 1:
            smallRotateRight(node);
            (*node)->diff = 0;
            if ((*node)->right != NULL) {
                (*node)->right->diff = 0;
            }
            break;
        case 0:
            smallRotateRight(node);
            (*node)->diff = -1;
            if ((*node)->right != NULL) {
                (*node)->right->diff = 1;
            }
            break;
        case -1:
            bigRotateRight(node);
            switch ((*node)->diff)
            {
                case -1:
                    (*node)->right->diff = 0;
                    (*node)->left->diff = 1;
                    break;
                case 1:
                    (*node)->right->diff = -1;
                    (*node)->left->diff = 0;
                    break;
                case 0:
                    (*node)->right->diff = 0;
                    (*node)->left->diff = 0;
                    break;
            }
            (*node)->diff = 0;
            break;
    }
}
