#include <stdio.h>
#define INF 9999
#define V 5
#define E 9

struct edge {
    int u, v, w;
};

struct edge edges[E];
int parent[V];

int edge_count(int graph[V][V], int n) {
    int ec = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] < INF) {
                edges[ec].u = i;
                edges[ec].v = j;
                edges[ec].w = graph[i][j];
                ec++;
            }
        }
    }
    return ec;
}

void sort(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].w > edges[j+1].w) {
                struct edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    parent[find(b)] = find(a);
}

void kruscal(int n) {
    sort(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            unionSet(edges[i].u, edges[i].v);
            printf("%d-%d\t%d\n", edges[i].u, edges[i].v, edges[i].w);
            count++;
        }
        if (count == V-1) break;
    }
}

int main() {
    int n = 5;
    int graph[5][5];

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

    for (int i = 0; i < n; i++)
        parent[i] = i;
    
    int ec = edge_count(graph, n);
    kruscal(ec);    
    
    return 0;
}