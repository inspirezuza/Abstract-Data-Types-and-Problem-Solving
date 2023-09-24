// ไฟล์ "week8.h" สำหรับนิสิตที่ต้องการเขียนโปรแกรมนอกเซิร์ฟเวอร์ adt เท่านั้น
// วาง week8.h ที่ directory เดียวกันกับโปรแกรม .c
// เปลี่ยนบรรทัด #include <week8.h> เป็น #include "week8.h"
// ก่อนส่งให้เปลี่ยนจาก #include "week8.h" กลับเป็น #include <week8.h> โดยไม่ต้องส่งไฟล์
// week8.h นั้น

#include "week8.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef __bin_tree__
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t tree_t;
#endif
// Write your code here
// ** Note that the attach() function has
// been implemented already and included
// in the week8.h header
// ...

int is_full(tree_t *t) {
    if (t == NULL) {
        return 1;
    }
    if ((t->left != NULL && t->right == NULL) ||
        (t->left == NULL && t->right != NULL)) {
        return 0;
    }
    return is_full(t->left) && is_full(t->right);
}

int count_node(tree_t *t) {
    if (t == NULL) {
        return 0;
    }
    return 1 + count_node(t->left) + count_node(t->right);
}

int maxDepth(tree_t *t) {
    if (t == NULL) {
        return 0;
    } else {
        int leftHeight = maxDepth(t->left);
        int rightHeight = maxDepth(t->right);

        return (leftHeight > rightHeight) ? (leftHeight + 1)
                                          : (rightHeight + 1);
    }
}

int is_perfect(tree_t *t) {
    int all_node = count_node(t);
    int height = maxDepth(t);
    return pow(2, height) - 1 == all_node;
}

int is_complete(tree_t *t) {

    if (t == NULL) {
        return 1;
    }

    tree_t *queue[2200];
    int front = -1, rear = -1;
    int null_seen = 0;

    queue[++rear] = t;

    while (rear != front) {
        tree_t *current = queue[++front];

        if (current == NULL) {
            null_seen = 1;
            continue;
        }
        if (null_seen) {
            return 0;
        }

        queue[++rear] = current->left;
        queue[++rear] = current->right;
    }

    return 1;
}

int is_degenerate(tree_t *t) {
    if (t == NULL) {
        return 1;
    }
    if (t->left != NULL && t->right != NULL) {
        return 0;
    }
    return is_degenerate(t->left) && is_degenerate(t->right);
}

int is_skewed(tree_t *t) {
    if (t == NULL) {
        return 1;
    }

    if (t->left != NULL) {
        while (t != NULL) {
            if (t->right != NULL) {
                return 0;
            }
            t = t->left;
        }
    } else if (t->right != NULL) {
        while (t != NULL) {
            if (t->left != NULL) {
                return 0;
            }
            t = t->right;
        }
    }
    return 1;
}

int main(void) {
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch;   // 0 root, 1 left, 2 right
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &parent, &child, &branch);
        t = attach(t, parent, child, branch);
    }
    printf("%d %d %d %d %d\n", is_full(t), is_perfect(t), is_complete(t),
           is_degenerate(t), is_skewed(t));
    return 0;
}
