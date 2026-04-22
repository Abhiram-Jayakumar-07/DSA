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

void BFS(int graph[][5], int start, int n) {
    int visited[5] = {0};
    int queue[5];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
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

    BFS(graph, 0, n);
    printf("\n");
    
    return 0;
}