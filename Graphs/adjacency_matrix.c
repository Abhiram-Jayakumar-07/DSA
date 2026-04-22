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

void deleteEdge(int graph[][5], int u, int v) {
    graph[u][v] = graph[v][u] = 0;
}

void printGraph(int graph[][5], int n) {
    printf("  ");
    for (int k = 0; k < n; k++) {
        printf("%d ", k);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", i);
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 5;
    int graph[5][5];

    initialize(graph, n);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);

    deleteEdge(graph, 0, 2);

    printGraph(graph, n);

    return 0;
}