#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionSort(int n, int *arr) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            swap(&arr[j - 1], &arr[j]);
            j--;
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionSort(n, arr);
    return 0;
}