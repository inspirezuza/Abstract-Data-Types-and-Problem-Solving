#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char string[16];
    int freq;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct MinHeap {
    int size;
    Node **array;
} MinHeap;

void swap(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MinHeap *heap, Node *newNode) {
    heap->size++;
    heap->array[heap->size] = newNode;

    int cur = heap->size;
    while (cur >= 1 && heap->array[cur]->freq < heap->array[cur / 2]->freq) {
        swap(&(heap->array[cur]), &(heap->array[cur / 2]));
        cur /= 2;
    }
}

Node *delete_min(MinHeap *heap) {
    if (heap->size == 0) {
        return NULL;
    }

    Node *temp = heap->array[1];
    heap->array[1] = heap->array[heap->size];
    heap->size--;

    int current_idx = 1;
    while (1) {
        int smallest = current_idx;
        int left = 2 * smallest;
        int right = 2 * smallest + 1;

        if (left <= heap->size &&
            heap->array[left]->freq < heap->array[smallest]->freq) {
            smallest = left;
        }
        if (right <= heap->size &&
            heap->array[right]->freq < heap->array[smallest]->freq) {
            smallest = right;
        }
        if (current_idx == smallest) {
            break;
        }
        swap(&heap->array[current_idx], &heap->array[smallest]);
        current_idx = smallest;
    }
    return temp;
}

// void bfs(MinHeap *heap) {
//     for (int i = 1; i <= heap->size; i++) {
//         printf("%s:%d ", heap->array[i]->string, heap->array[i]->freq);
//     }
//     printf("\n");
// }

// void dfs(Node *root) {
//     if (root == NULL) {
//         return;
//     }
//     printf("%s:%d ", root->string, root->freq);
//     dfs(root->left);
//     dfs(root->right);
// }

void huffmanDfs(Node *root, char *code, int size) {
    if (root == NULL) {
        return;
    }
    if (strcmp(root->string, "$") != 0) {
        printf("%s: ", root->string);
        for (int i = 0; i < size; i++) {
            printf("%c", code[i]);
        }
        printf("\n");
        return;
    }
    code[size] = '0';
    huffmanDfs(root->left, code, size + 1);

    code[size] = '1';
    huffmanDfs(root->right, code, size + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    MinHeap *myheap = (MinHeap *) malloc(sizeof(MinHeap));
    myheap->array = (Node **) malloc(sizeof(Node *) * (n + 1));
    myheap->size = 0;

    for (int i = 0; i <= n; i++) {
        myheap->array[i] = (Node *) malloc(sizeof(Node));
    }

    for (int i = 1; i <= n; i++) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->left = NULL;
        newNode->right = NULL;
        scanf("%s %d", newNode->string, &newNode->freq);
        insert(myheap, newNode);
    }
    while (myheap->size != 1) {
        Node *left = delete_min(myheap);
        Node *right = delete_min(myheap);
        Node *newNode = (Node *) malloc(sizeof(Node));
        strcpy(newNode->string, "$");
        newNode->freq = left->freq + right->freq;
        newNode->left = left;
        newNode->right = right;
        insert(myheap, newNode);
    }
    char code[16] = {};
    huffmanDfs(myheap->array[1], code, 0);

    return 0;
}