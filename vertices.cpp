#include <stdio.h>
#include <limits.h>

#define MAX 100

int adj[MAX][MAX];
int dist[MAX];
int visited[MAX];

void dijkstra(int n, int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        visited[u] = 1;

        for (int j = 0; j < n; j++) {
            if (adj[u][j] != 0 && !visited[j]) {
                int new_dist = dist[u] + adj[u][j];
                if (new_dist < dist[j]) {
                    dist[j] = new_dist;
                }
            }
        }
    }
}

int main() {
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter the edges: ");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(n, src);

    printf("Shortest distances from vertex %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, dist[i]);
    }

    return 0;
}