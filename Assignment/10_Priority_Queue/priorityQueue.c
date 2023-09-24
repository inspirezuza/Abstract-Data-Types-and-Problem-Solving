#include <stdio.h>
#include <stdlib.h>
typedef struct heap {
    int *data;
    int last_index;
} heap_t;

heap_t *init_heap(int m) {
    heap_t *heap = (heap_t *) malloc(sizeof(heap_t));
    heap->data = (int *) malloc(sizeof(int) * (m + 1));
    heap->last_index = 0;
    return heap;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1
void insert(heap_t *heap, int key) {
    if (heap->last_index == 0) {
        heap->last_index = 1;
        heap->data[1] = key;
    } else {
        heap->last_index++;
        heap->data[heap->last_index] = key;

        int current_index = heap->last_index;
        while (current_index > 1 &&
               heap->data[current_index] > heap->data[current_index / 2]) {
            swap(&heap->data[current_index], &heap->data[current_index / 2]);
            current_index /= 2;
        }
    }
}

int max(int a, int b) { return a > b ? a : b; }

// 2
void delete_max(heap_t *heap) {
    if (heap->last_index == 0) {
        return;
    }

    heap->data[1] = heap->data[heap->last_index];
    heap->last_index--;
    int current_index = 1;
    while (1) {
        int largest = current_index;
        int left = 2 * current_index;
        int right = 2 * current_index + 1;

        if (left <= heap->last_index &&
            heap->data[left] > heap->data[largest]) {
            largest = left;
        }
        if (right <= heap->last_index &&
            heap->data[right] > heap->data[largest]) {
            largest = right;
        }
        if (largest == current_index) {
            break;
        }
        swap(&heap->data[largest], &heap->data[current_index]);
        current_index = largest;
    }
}

// 3
int find_max(heap_t *heap) {
    if (heap->last_index == 0) {
        return -1;
    }
    return heap->data[1];
}

// 4
void update_key(heap_t *heap, int old, int new) {
    if (heap->last_index == 0) {
        return;
    }
    for (int i = 1; i <= heap->last_index; i++) {
        if (heap->data[i] == old) {
            heap->data[i] = new;

            while (i > 1 && heap->data[i] > heap->data[i / 2]) {
                swap(&heap->data[i], &heap->data[i / 2]);
                i /= 2;
            }

            int current_index = i;
            while (1) {
                int largest = current_index;
                int left = 2 * current_index;
                int right = 2 * current_index + 1;

                if (left <= heap->last_index &&
                    heap->data[left] > heap->data[largest]) {
                    largest = left;
                }
                if (right <= heap->last_index &&
                    heap->data[right] > heap->data[largest]) {
                    largest = right;
                }
                if (largest == current_index) {
                    break;
                }
                swap(&heap->data[largest], &heap->data[current_index]);
                current_index = largest;
            }
        }
    }
}

// 5
void bfs(heap_t *heap) {
    for (int i = 1; i <= heap->last_index; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main(void) {
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;
    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);
    for (i = 0; i < n; i++) {
        scanf("%d", &command);
        switch (command) {
        case 1:
            scanf("%d", &data);
            insert(max_heap, data);
            break;
        case 2:
            delete_max(max_heap);
            break;
        case 3:
            printf("%d\n", find_max(max_heap));
            break;
        case 4:
            scanf("%d %d", &old_key, &new_key);
            update_key(max_heap, old_key, new_key);
            break;
        case 5:
            bfs(max_heap);
            break;
        }
    }
    return 0;
}