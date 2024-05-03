#include "rotate.h"


bool addToAvlTree(AvlNode** root, int value) {
    if (root == NULL) {
        return false;
    }

    AvlNode* newNode = malloc(sizeof(AvlNode));
    if (newNode == NULL) {
        return false;
    }

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->diff = 0;

    if (*root == NULL) {
        *root = newNode;
        return true;
    }

    AvlNode* iter = *root;
    while (iter != NULL) {
        if (value < iter->value) {
            if (iter->left != NULL) {
                iter = iter->left;
            }
            else {
                newNode->parent = iter;
                iter->left = newNode;
                break;
            }
        }
        else if (value > iter->value) {
            if (iter->right != NULL) {
                iter = iter->right;
            }
            else {
                newNode->parent = iter;
                iter->right = newNode;
                break;
            }
        }
        else {
            return false;
        }
    }

    iter = newNode;
    AvlNode* parent = iter->parent;
    while (parent != NULL) {
        if (parent->value > iter->value) {
            parent->diff++;
        }
        else if (parent->value < iter->value) {
            parent->diff--;
        }

        switch (parent->diff)
        {
        // Высота поддерева не изменилась
        case 0:
            return true;
        // Нужен левый поворот
        case -2:
            rotateLeft(&parent);
            break;
        // Нужен правый поворот
        case 2:
            rotateRight(&parent);
            break;
        }

        if (parent->parent == NULL) {
            *root = parent;
            return true;
        }

        // После вращения баланс восстановился
        if (parent->diff == 0) {
            return true;
        }
        iter = iter->parent;

        parent = iter->parent;
    }

    return true;
}


void clearAvlTreeRec(AvlNode* iter) {
    if (iter == NULL) {
        return;
    }
    clearAvlTreeRec(iter->left);
    clearAvlTreeRec(iter->right);
    free(iter);
}

bool clearAvlTree(AvlNode** root) {
    if (root == NULL) {
        return false;
    }
    clearAvlTreeRec(*root);
    *root = NULL;
    return true;
}
