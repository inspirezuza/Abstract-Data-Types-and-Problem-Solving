#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10000

int n;
int graph[MAX_NODES][MAX_NODES];
int transpose[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int stack[MAX_NODES];
int stack_top = -1;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void trashsort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void dfs1(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[v][i]) {
            dfs1(i);
        }
    }
    stack[++stack_top] = v;
}

void dfs2(int v, int *count, int traverse[]) {
    traverse[*count] = v;
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && transpose[v][i]) {
            (*count)++;
            dfs2(i, count, traverse);
        }
    }
}

void addEdge(int u, int v) {
    graph[u][v] = 1;
    transpose[v][u] = 1;
}

int findMaxSCC() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    int max_size = 0;
    int max_scc_index = -1;
    int answer[MAX_NODES];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    while (stack_top >= 0) {
        int v = stack[stack_top--];
        if (!visited[v]) {
            int scc_size = 0;

            int traverse[MAX_NODES] = {};
            int count = 0;
            dfs2(v, &count, traverse);
            if (count > max_size) {
                for (int i = 0; i < count + 1; i++) {
                    answer[i] = traverse[i];
                }
                max_size = count;
                max_scc_index = v;
            }
        }
    }
    trashsort(answer, max_size + 1);
    for (int i = 0; i < max_size + 1; i++) {
        printf("%d ", answer[i]);
    }
}

int main() {
    int m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
            transpose[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    findMaxSCC();

    return 0;
}
