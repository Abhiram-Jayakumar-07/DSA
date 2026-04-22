#include <stdio.h>

void initialize(int graph[][5], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[][5], int u, int v) {
    graph[u][v] = graph[v][u] = 1;
}

int dfs_cycle(int graph[][5], int visited[], int n, int v, int parent) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1) {
            if (visited[i] == 0) {
                if (dfs_cycle(graph, visited, n, i, v))
                    return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int has_cycle(int graph[][5], int n) {
    int visited[5] = {0};
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && dfs_cycle(graph, visited, n, i, -1))
            return 1;
    }
    return 0;
}

int main() {
    int n = 5;
    int graph[5][5];
    int visited[5] = {0};

    initialize(graph, n);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    printf("%d\n", has_cycle(graph, n));
    
    return 0;
}