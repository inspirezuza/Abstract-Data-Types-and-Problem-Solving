// ไฟล์ "week8.h" สำหรับนิสิตที่ต้องการเขียนโปรแกรมนอกเซิร์ฟเวอร์ adt เท่านั้น
// วาง week8.h ที่ directory เดียวกันกับโปรแกรม .c
// เปลี่ยนบรรทัด #include <week8.h> เป็น #include "week8.h"
// ก่อนส่งให้เปลี่ยนจาก #include "week8.h" กลับเป็น #include <week8.h> โดยไม่ต้องส่งไฟล์
// week8.h นั้น

#include <stdio.h>
#include <stdlib.h>
#include <week8.h>
#ifndef __bin_tree__
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t tree_t;
#endif
void print_preorder_helper(tree_t *t) {
    if (t == NULL) {
        return;
    }
    printf("%d ", t->data);
    print_preorder_helper(t->left);
    print_preorder_helper(t->right);
}

void print_preorder(tree_t *t) {
    print_preorder_helper(t);
    printf("\n");
}

void print_postorder_helper(tree_t *t) {
    if (t == NULL) {
        return;
    }
    print_postorder_helper(t->left);
    print_postorder_helper(t->right);
    printf("%d ", t->data);
}

void print_postorder(tree_t *t) {
    print_postorder_helper(t);
    printf("\n");
}
void print_inorder_helper(tree_t *t) {
    if (t == NULL) {
        return;
    }
    print_inorder_helper(t->left);
    printf("%d ", t->data);
    print_inorder_helper(t->right);
}

void print_inorder(tree_t *t) {
    print_inorder_helper(t);
    printf("\n");
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
    print_preorder(t);
    print_postorder(t);
    print_inorder(t);
    return 0;
}