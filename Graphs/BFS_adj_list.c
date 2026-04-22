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

void BFS(struct graphtag graph[], int start) {
    int visited[5] = {0};
    int queue[5];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct edgetag *temp = graph[v].start;
        while (temp) {
            if (visited[temp->vertex] == 0) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n = 5;
    struct graphtag graph[n];
    int visited[5] = {0};

    initialize(graph, n);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);

    BFS(graph, 0);
    printf("\n");

    return 0;
}