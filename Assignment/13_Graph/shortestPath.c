#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10000
#define MAX_EDGES 10000

typedef struct {
    int node;
    int weight;
} Edge;

int n, m, p;
Edge graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];

void dijkstra(int start) {
    int visited[MAX_NODES] = {0};

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    for (int i = 0; i < n; i++) {
        int min_dist = INT_MAX;
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = 1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[u][j].weight > 0) {
                if (dist[u] + graph[u][j].weight < dist[j]) {
                    dist[j] = dist[u] + graph[u][j].weight;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &p);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j].weight = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v].weight = w;
        graph[v][u].weight = w;
    }

    for (int i = 0; i < p; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        dijkstra(s);

        if (dist[t] == INT_MAX) {
            printf("-1\n");
        } else {
            printf("%d\n", dist[t]);
        }
    }

    return 0;
}
