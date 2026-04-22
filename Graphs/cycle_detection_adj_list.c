#include <stdio.h>
#include <stdlib.h>

struct edgetag {
    int vertex;
    struct edgetag *next;
};

struct graphtag {
    int vertex;
    struct edgetag *start;
};

void initialize(struct graphtag graph[], int n) {
    for (int i = 0; i < n; i++) {
        graph[i].vertex = i;
        graph[i].start = NULL;
    }
}

void addEdge(struct graphtag graph[], int u, int v) {
    struct edgetag *newNode = malloc(sizeof(struct edgetag));
    newNode->vertex = v;
    newNode->next = graph[u].start;
    graph[u].start = newNode;

    newNode = malloc(sizeof(struct edgetag));
    newNode->vertex = u;
    newNode->next = graph[v].start;
    graph[v].start = newNode;
}

int dfs_cycle(struct graphtag graph[], int visited[], int v, int parent) {
    visited[v] = 1;
    struct edgetag *temp = graph[v].start;
    while (temp) {
        if (visited[temp->vertex] == 0) {
            if (dfs_cycle(graph, visited, temp->vertex, v))
                return 1;
        } else if (temp->vertex != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int has_cycle(struct graphtag graph[], int n) {
    int visited[5] = {0};
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && dfs_cycle(graph, visited, i, -1))
            return 1;
    }
    return 0;
}

int main() {
    int n = 5;
    struct graphtag graph[n];

    initialize(graph, n);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    printf("%d\n", has_cycle(graph, n));

    return 0;
}