#include <stdio.h>
#define INF 9999

void initialize(int graph[][5], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }
}

int min(int key[], int visited[], int n) {
    int min = INF, index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

void prim(int graph[][5], int n) {
    int key[n], visited[n], parent[n];
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = 0;
        parent[i]= -1;
    }
    key[0] = 0;

    while (1) {
        int u = min(key, visited, n);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF && !visited[v]) {
                if (graph[u][v] < key[v]){
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    for (int i = 1; i < n; i++) {
        printf("%d: %d\t%d\n", i, parent[i], graph[i][parent[i]]);
    }
    printf("\n");
}

int main() {
    int n = 5;
    int graph[5][5];
    int visited[5] = {0};

    initialize(graph, n);

    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 4;

    graph[1][2] = graph[2][1] = 2;
    graph[1][3] = graph[3][1] = 5;

    graph[2][3] = graph[3][2] = 1;
    graph[2][4] = graph[4][2] = 3;

    graph[3][4] = graph[4][3] = 2;

    prim(graph, n);
    
    return 0;
}