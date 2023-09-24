#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t bst_t;
void show(bst_t *t) {
    if (t == NULL) {
        return;
    }
    printf("%d -> ", t->data);
    show(t->left);
    show(t->right);
}

// 1
bst_t *insert(bst_t *t, int data) {
    bst_t *newnode = (bst_t *) malloc(sizeof(bst_t));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if (t == NULL) {
        return newnode;
    }
    bst_t *tmp = t;
    while (tmp != NULL) {
        if (data < tmp->data) {
            if (tmp->left == NULL) {
                tmp->left = newnode;
                break;
            }
            tmp = tmp->left;
        } else {
            if (tmp->right == NULL) {
                tmp->right = newnode;
                break;
            }
            tmp = tmp->right;
        }
    }
    return t;
}

// 2
bst_t *delete(bst_t *t, int data) {
    if (t == NULL) {
        return t;
    }
    if (data < t->data) {
        t->left = delete (t->left, data);
    } else if (data > t->data) {
        t->right = delete (t->right, data);
    } else {
        if (t->left == NULL) {
            bst_t *tmp = t->right;
            free(t);
            return tmp;
        } else if (t->right == NULL) {
            bst_t *tmp = t->left;
            free(t);
            return tmp;
        } else {
            bst_t *tmp = t->right;
            while (tmp->left != NULL) {
                tmp = tmp->left;
            }
            t->data = tmp->data;
            t->right = delete (t->right, tmp->data);
        }
    }

    return t;
}

// 3
int find(bst_t *t, int data) {
    if (t == NULL) {
        return 0;
    }
    if (t->data == data) {
        return 1;
    }
    return find(t->left, data) || find(t->right, data);
}

// 4
int find_min(bst_t *t) {
    bst_t *tmp = t;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp->data;
}

// 5
int find_max(bst_t *t) {
    bst_t *tmp = t;
    while (tmp->right != NULL) {
        tmp = tmp->right;
    }
    return tmp->data;
}

int main(void) {
    bst_t *t = NULL;
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
            scanf("%d", &data);
            printf("%d\n", find(t, data));
            break;
        case 4:
            printf("%d\n", find_min(t));
            break;
        case 5:
            printf("%d\n", find_max(t));
            break;
        }
    }
    return 0;
}