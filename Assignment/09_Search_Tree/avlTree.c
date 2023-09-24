#include "week9.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef __avl_tree__
typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t avl_t;
#endif
// Write your code here
// ** Note that the print_tree() function
// has been implemented already and
// included in the week9.h header
// ...

int max(int a, int b) { return (a > b) ? a : b; }

int height(avl_t *t) {
    if (t == NULL) {
        return 0;
    }
    return t->height;
}

int getBalance(avl_t *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

avl_t *rotateRight(avl_t *y) {
    avl_t *x = y->left;
    avl_t *xy = x->right;
    x->right = y;
    y->left = xy;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

avl_t *rotateLeft(avl_t *x) {
    avl_t *y = x->right;
    avl_t *yx = y->left;
    y->left = x;
    x->right = yx;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

avl_t *insert(avl_t *t, int data) {
    if (t == NULL) {
        avl_t *tmp = (avl_t *) malloc(sizeof(avl_t));
        tmp->data = data;
        tmp->height = 1;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }
    if (data < t->data) {
        t->left = insert(t->left, data);
    } else if (data > t->data) {
        t->right = insert(t->right, data);
    }
    t->height = max(height(t->left), height(t->right)) + 1;

    int balance = height(t->left) - height(t->right);

    // Left Left Case
    if (balance > 1 && data < t->left->data)
        return rotateRight(t);

    // Right Right Case
    if (balance < -1 && data > t->right->data)
        return rotateLeft(t);

    // Left Right Case
    if (balance > 1 && data > t->left->data) {
        t->left = rotateLeft(t->left);
        return rotateRight(t);
    }

    // Right Left Case
    if (balance < -1 && data < t->right->data) {
        t->right = rotateRight(t->right);
        return rotateLeft(t);
    }

    return t;
}

avl_t *delete(avl_t *t, int data) {
    if (t == NULL)
        return t;

    if (data < t->data)
        t->left = delete (t->left, data);
    else if (data > t->data)
        t->right = delete (t->right, data);
    else {
        if (t->left == NULL) {
            avl_t *tmp = t->right;
            free(t);
            return tmp;
        } else if (t->right == NULL) {
            avl_t *tmp = t->left;
            free(t);
            return tmp;
        } else {
            avl_t *tmp = t->right;
            while (tmp->left != NULL) {
                tmp = tmp->left;
            }
            t->data = tmp->data;
            t->right = delete (t->right, tmp->data);
        }
    }
    t->height = max(height(t->left), height(t->right)) + 1;

    int balance = height(t->left) - height(t->right);

    // Left Left Case
    if (balance > 1 && getBalance(t->left) >= 0)
        return rotateRight(t);

    // Right Right Case
    if (balance < -1 && getBalance(t->right) <= 0)
        return rotateLeft(t);

    // Right Left Case
    if (balance < -1 && getBalance(t->right) > 0) {
        t->right = rotateRight(t->right);
        return rotateLeft(t);
    }

    return t;
}

int main(void) {
    avl_t *t = NULL;
    int n, i;
    int command, data;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &command);
        switch (command) {
        case 1:
            scanf("%d", &data);
            t = insert(t, data);
            break;
        case 2:
            scanf("%d", &data);
            t = delete (t, data);
            break;
        case 3:
            print_tree(t);
            break;
        }
    }
    return 0;
}