#include "avl_tree.h"

bool delFromAvlTree(AvlNode** root, int value) {
    if (root == NULL) {
        return false;
    }

    AvlNode* iter = *root;
    while (iter != NULL) {
        if (value < iter->value) {
            iter = iter->left;
        }
        else if (value > iter->value) {
            iter = iter->right;
        }
        else {
            break;
        }
    }

    if (iter == NULL) {
        return false;
    }

    AvlNode *toDelete = iter;
    AvlNode* parent = iter->parent;

    if (toDelete->left == NULL && toDelete->right == NULL) {
        if (toDelete->parent != NULL) {
            // Если удаляемый был слева
            if (toDelete->value < toDelete->parent->value) {
                toDelete->parent->left = NULL;
                toDelete->parent->diff--;
            }
            // Справа
            else {
                toDelete->parent->right = NULL;
                toDelete->parent->diff++;
            }
        }
        else {
            (*root) = NULL;
        }

        iter = NULL;
    }
    else if (toDelete->left == NULL) {
        if (toDelete->parent != NULL) {
            // Если удаляемый был слева
            if (toDelete->value < toDelete->parent->value) {
                toDelete->parent->left = toDelete->right;
            }
                // Справа
            else {
                toDelete->parent->right = toDelete->right;
            }
        } else {
            *root = toDelete->right;
        }
        toDelete->right->parent = toDelete->parent;
        iter = toDelete->right;
    }
    else if (toDelete->right == NULL) {
        if (toDelete->parent != NULL) {
            // Если удаляемый был слева
            if (toDelete->value < toDelete->parent->value) {
                toDelete->parent->left = toDelete->left;
            }
                // Справа
            else {
                toDelete->parent->right = toDelete->left;
            }
        }
        else {
            *root = toDelete->left;
        }
        toDelete->left->parent = toDelete->parent;

        iter = toDelete->left;
    }
    else {
        AvlNode* minIter = iter->right;
        bool stepMade = false;
        while (minIter->left != NULL) {
            stepMade = true;
            minIter = minIter->left;
        }
        // Сохраняем правое поддерево у наим. элемента, если есть
        AvlNode *minIterRight = minIter->right;
        // Делаем правое поддерево удалемого правым поддеревом наименьшего
        minIter->right = toDelete->right;
        toDelete->right->parent = minIter;
        // Аналогично с левым
        minIter->left = toDelete->left;
        toDelete->left->parent = minIter;
        // Правое поддерево наименьшего теперь левое поддерево его предыдущего родителя
        if (stepMade) {
            minIter->parent->left = minIterRight;
            minIterRight->parent = minIter->parent;
        }
        // Связываем также родителя удаляемого элемента с наименьшим
        if (toDelete->parent != NULL) {
            minIter->parent = toDelete->parent;
            // Если удаляемый был слева
            if (toDelete->value < toDelete->parent->value) {
                toDelete->parent->left = minIter;
            }
            // Справа
            else {
                toDelete->parent->right = minIter;
            }
        }
        else {
            *root = minIter;
        }

        iter = minIter;
    }

    free(toDelete);

    while (parent != NULL) {
        if (iter != NULL && iter->value < parent->value) {
            parent->diff--;
        }
        else if (iter != NULL && iter->value > parent->value)  {
            parent->diff++;
        }

        switch (parent->diff)
        {
            // Высота поддерева не изменилась
            case 1:
            case -1:
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
        if (parent->diff == -1 || parent->diff == 1) {
            return true;
        }
        iter = parent;
        parent = iter->parent;
    }

    return true;
}