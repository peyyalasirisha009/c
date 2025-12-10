#include <stdio.h>

int g[10][10], vis[10], disc[10], low[10], t = 0, n;

void dfs(int u, int p) {
    vis[u] = 1;
    disc[u] = low[u] = ++t;
    int child = 0;

    for (int v = 1; v <= n; v++) {
        if (g[u][v]) {
            if (!vis[v]) {
                child++;
                dfs(v, u);
                if (low[v] >= disc[u] && p != -1)
                    printf("%d ", u);
                if (low[v] < low[u])
                    low[u] = low[v];
            }
            else if (v != p && disc[v] < low[u])
                low[u] = disc[v];
        }
    }

    if (p == -1 && child > 1)
        printf("%d ", u);
}

int main() {
    int e, u, v;
    scanf("%d %d", &n, &e);
    while (e--) {
        scanf("%d %d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }
    dfs(1, -1);
}