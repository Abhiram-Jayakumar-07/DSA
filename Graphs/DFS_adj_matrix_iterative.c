#include <stdio.h>
#define MAX 5

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

void DFS(int graph[][5], int start, int n) {
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;

    stack[++top] = start;
    while (top != -1) {
        int v = stack[top--];
        visited[v] = 1;
        printf("%d ", v);

        for (int i = n - 1; i >= 0; i--) {
            if (graph[v][i] == 1 && visited[i] == 0)
                stack[++top] = i;
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

    DFS(graph, 0, n);
    printf("\n");
    
    return 0;
}