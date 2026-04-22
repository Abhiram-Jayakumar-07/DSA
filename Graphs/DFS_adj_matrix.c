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

void DFS(int graph[][5], int visited[], int v, int n) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0)
            DFS(graph, visited, i, n);
    }
}

int main() {
    int n = 5;
    int graph[5][5];
    int visited[5] = {0};

    initialize(graph, n);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);

    DFS(graph, visited, 0, n);
    printf("\n");
    
    return 0;
}