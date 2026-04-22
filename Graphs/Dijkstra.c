#include <stdio.h>
#define INF 9999

int min(int d[], int visited[], int n) {
    int min = INF, index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && d[i] < min) {
            min = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[][5], int n, int src) {
    int d[n], visited[n];
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        visited[i] = 0;
    }
    d[src] = 0;

    while (1) {
        int u = min(d, visited, n);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF && !visited[v]){
                if (d[v] > d[u] + graph[u][v])
                    d[v] = d[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[i] == INF)
            printf("%d: INF\n", i);
        else
            printf("%d: %d\n", i, d[i]);
    }
    printf("\n");
}

int main() {
    int n = 5;
    int graph[5][5];
    int visited[5] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 4;

    graph[1][2] = graph[2][1] = 2;
    graph[1][3] = graph[3][1] = 5;

    graph[2][3] = graph[3][2] = 1;
    graph[2][4] = graph[4][2] = 3;

    graph[3][4] = graph[4][3] = 2;

    dijkstra(graph, n, 0);
    
    return 0;
}